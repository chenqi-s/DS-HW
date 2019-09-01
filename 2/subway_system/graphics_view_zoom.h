#ifndef GRAPHICS_VIEW_ZOOM_H
#define GRAPHICS_VIEW_ZOOM_H

#include <QObject>
#include <QGraphicsView>
#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QtCore/qmath.h>


#define maxmapsize 723
#define minmapsize 8

class Graphics_view_zoom : public QObject {
  Q_OBJECT
public:
  Graphics_view_zoom(QGraphicsView* view,QSlider *slider);
  void gentle_zoom(double factor);
  void set_modifiers(Qt::KeyboardModifiers modifiers);
  void set_zoom_factor_base(double value);

private:
  QGraphicsView* _view;
  QSlider *slider;
  Qt::KeyboardModifiers _modifiers;
  double _zoom_factor_base;
  double size;
  int dur;
  QPointF target_scene_pos, target_viewport_pos;

  bool eventFilter(QObject* object, QEvent* event);
  void originalview();
  void wheel_view(QEvent *event);
signals:
  void zoomed();
};

#endif // GRAPHICS_VIEW_ZOOM_H
