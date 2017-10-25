#include <iostream>

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_box(box);
void set_volume(box *);

int main()
{
	box boxs = { "my box",2,5,12,100 };

	show_box(boxs);
	set_volume(&boxs);
	show_box(boxs);

	return 0;
}

void show_box(box boxs)
{
	std::cout << "Maker is " << boxs.maker << std::endl;
	std::cout << "Height is " << boxs.height << std::endl;
	std::cout << "Width is " << boxs.width << std::endl;
	std::cout << "Length is " << boxs.length << std::endl;
	std::cout << "Volume is " << boxs.volume << std::endl;
}

void set_volume(box *boxs)
{
	boxs->volume = (boxs->height*boxs->width*boxs->length);
}