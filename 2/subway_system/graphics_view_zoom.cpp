#include "graphics_view_zoom.h"
#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>
#include <qmath.h>

Graphics_view_zoom::Graphics_view_zoom(QGraphicsView* view,QSlider *slid)
    : QObject(view), _view(view),slider(slid)
{
    _view->viewport()->installEventFilter(this);
    slider->installEventFilter(this);
    _view->setMouseTracking(true);
    _modifiers = Qt::ControlModifier;
    _zoom_factor_base = 1.0015;
    size=100;
    slider->setMinimum(0);  // 最小值
    slider->setMaximum(200);  // 最大值
    dur = slider->maximum() - slider->minimum();
    slider->setSingleStep(1); // 步长
    slider->setValue(size); // 设置滑动条初始值

    //connect(slider, SIGNAL(valueChanged(int)),this, SLOT(translabel(int)));

}



void Graphics_view_zoom::gentle_zoom(double factor) {
    _view->scale(factor, factor);                     //scaling the view with the factor(wheel)
    _view->centerOn(target_scene_pos);                //change the center of the view with mouse move
    QPointF delta_viewport_pos = target_viewport_pos - QPointF(_view->viewport()->width() / 2.0,
                                                               _view->viewport()->height() / 2.0);
    QPointF viewport_center = _view->mapFromScene(target_scene_pos) - delta_viewport_pos;
    _view->centerOn(_view->mapToScene(viewport_center.toPoint()));
    emit zoomed();

    size/=factor;

}


void Graphics_view_zoom::set_modifiers(Qt::KeyboardModifiers modifiers) {
    _modifiers = modifiers;

}

void Graphics_view_zoom::set_zoom_factor_base(double value) {
    _zoom_factor_base = value;
}



void Graphics_view_zoom::originalview()
{
//    target_viewport_pos =QPointF(_view->viewport()->width() / 2.0,
//                                 _view->viewport()->height() / 2.0);
//    _view->centerOn(_view->mapToScene(target_viewport_pos.toPoint()));
    _view->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    QMatrix q;
    q.setMatrix(1,_view->matrix().m12(),_view->matrix().m21(),1,_view->matrix().dx(),_view->matrix().dy());
    _view->setMatrix(q,false);
    size=100;
    slider->setValue(size); // 设置滑动条初始值

}

void Graphics_view_zoom::wheel_view(QEvent *event)
{
    QWheelEvent* wheel_event = static_cast<QWheelEvent*>(event);
    if (QApplication::keyboardModifiers() == _modifiers)
    {
        if (wheel_event->orientation() == Qt::Vertical )
        {
            if( size>minmapsize && size<maxmapsize)
            {
                double angle = wheel_event->angleDelta().y();
                double factor = qPow(_zoom_factor_base, angle);
                slider->setValue(qLn(factor)*48.0+slider->sliderPosition());
                gentle_zoom(factor);
            }
            else if(size<=minmapsize)
                gentle_zoom(0.99);
            else if(size>=maxmapsize)
                gentle_zoom(1.01);
        }
    }
}



bool Graphics_view_zoom::eventFilter(QObject *object, QEvent *event) {
    if(object==slider)
    {
        if (event->type()==QEvent::MouseButtonPress)           //判断类型
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) //判断左键
            {
                double pos = slider->maximum() - dur * ((double)mouseEvent->y() / slider->height());
                if(pos != slider->sliderPosition())
                {
                    gentle_zoom(qExp(((double)pos-(double)slider->sliderPosition())/48.0));
                    slider->setValue(pos);
                }
            }
        }
        else if(event->type()==QEvent::Wheel )
            wheel_view(event);
    }
    else if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
        QPointF delta = target_viewport_pos - mouse_event->pos();
        if (qAbs(delta.x()) > 5 || qAbs(delta.y()) > 5)
        {
            target_viewport_pos = mouse_event->pos();
            target_scene_pos = _view->mapToScene(mouse_event->pos());
        }
    }
    else if (event->type() == QEvent::Wheel)
        wheel_view(event);
    else if(event->type()==QEvent::MouseButtonDblClick)
        originalview();

    Q_UNUSED(object)
    return false;
}
