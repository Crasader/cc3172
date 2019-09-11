#include "s565.h"

s565::s565() :color(0xFFFF)
{

}

s565::s565(uchar red, uchar green, uchar blue) : r(red >> 3), g(green >> 2), b(blue >> 3)
{

}

void s565::toBlick()
{
	if (color == 0)
	{
		return;
	}
	if (r > 0x18)
	{
		r = 0x1F;
	}
	else
	{
		r += 0x07;
	}
	if (g > 0x31)
	{
		g = 0x3F;
	}
	else
	{
		g += 0x0E;
	}
	if (b < 0x0A)
	{
		b = 0x0;
	}
	else
	{
		b -= 0x0A;
	}
}

void s565::toLight()
{
	if (color == 0)
	{
		return;
	}
	if (r > 0x18)
	{
		r = 0x1F;
	}
	else
	{
		r += 0x07;
	}
	if (g > 0x31)
	{
		g = 0x3F;
	}
	else
	{
		g += 0x0E;
	}
	if (b > 0x18)
	{
		b = 0x1F;
	}
	else
	{
		b += 0x07;
	}
}

void s565::toAlpha(uchar Ox20)
{
	if (Ox20 == 0x20)
	{
		return;
	}
	r = r * Ox20 / 0x20;
	g = g * Ox20 / 0x20;
	b = b * Ox20 / 0x20;
}

void s565::toOpacity(s565& src2des, uchar opacity)const
{
	uchar dealpha = 0x20 - opacity;
	src2des.r = (r * opacity + src2des.r * dealpha) >> 5;
	src2des.g = (g * opacity + src2des.g * dealpha) >> 5;
	src2des.b = (b * opacity + src2des.b * dealpha) >> 5;
}

ulong s565::to8888(uchar Ox20) const
{
	if (Ox20 == 0x20 || Ox20 == 0x1F)
	{
		Ox20 = 0xFF;
	}
	else if (Ox20 > 0)
	{
		Ox20 = Ox20 << 3 | 7;
	}
	return ((r << 3 | 7) << 0) | ((g << 2 | 7) << 8) | ((b << 3 | 7) << 16) | Ox20 << 24;
}

ushort s565::to4444(uchar Ox20) const
{
	if (Ox20 == 0x20)
	{
		Ox20 = 0x1F;
	}
	return (r >> 1 << 0) | (g >> 2 << 4) | (b >> 1 << 8) | Ox20 >> 1 << 12;
}

const s565 s565::WHITE(0xFF, 0xFF, 0xFF);
const s565 s565::YELLOW(0xFF, 0xFF, 0);
const s565 s565::GREEN(0, 0xFF, 0);
const s565 s565::BLUE(0, 0, 0xFF);
const s565 s565::RED(0xFF, 0, 0);
const s565 s565::MAGENTA(0xFF, 0, 0xFF);
const s565 s565::BLACK(0, 0, 0);
const s565 s565::ORANGE(0xFF, 127, 0);
const s565 s565::GRAY(166, 166, 166);