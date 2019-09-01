#include "png.h"

png::png(int _w, int _h)
	:w(_w), h(_h)
{
	lodepng_palette_add(&state.info_png.color, 0, 0, 0, 1);
	lodepng_palette_add(&state.info_raw, 0, 0, 0, 1);
	state.info_png.color.colortype = LCT_PALETTE; 
	state.info_png.color.bitdepth = 4;
	state.info_raw.colortype = LCT_PALETTE;
	state.info_raw.bitdepth = 4;
	state.encoder.auto_convert = 1; 
	image.resize((w * h * 4 + 7) / 8, 0);
}

void png::point(int x, int y, int color)
{
	size_t byte_index = (y * w + x) / 2;
	bool byte_half = (y * w + x) % 2 == 1;
	image[byte_index] |= (unsigned char)(color << (byte_half ? 0 : 4));
}

void png::circle(int a, int b, int r, int color){
	for(int x = a-r; x <= a+r; x++)
		for(int y = b-sqrt(r*r-(x-a)*(x-a)); y <= b+sqrt(r*r-(x-a)*(x-a)); y++)
		{
			point(x, y, color);
		}	
}
void png::line(int x1, int y1, int x2, int y2, int r, int color)
{
	if(r >= 0){
		for(int i=-r/2;i<=r/2;i++){
			line(x1+i, y1, x2+i, y2, -1, color);
			line(x1, y1+i, x2, y2+i, -1, color);
		}
	}
	int dx=x2-x1, dy=y2-y1, px=1, py=1;
	if(dx < 0)px=-1, dx=-dx;
	if(dy < 0)py=-1, dy=-dy;
	if(dx>=dy)
	{
		for(int e=dy-dx/2;x1-x2;x1+=px){
			point(x1,y1,color);
			if(e>0)y1+=py, e-=dx;
			e+=dy;
		}
	}
	else
	{
		for(int e=dx-dy/2;y1-y2;y1+=py){
			point(x1,y1,color);
			if(e>0)x1+=px, e-=dy;
			e+=dx;
		}
	}
}
void png::save(QString filename)
{
	std::vector<unsigned char> buffer;
	lodepng::encode(buffer, image.empty() ? 0 : &image[0], w, h, state);
    lodepng::save_file(buffer, filename);
}
