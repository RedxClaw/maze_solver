#include "presets.h"

double ft_gettime(struct timeval t1, struct timeval t2)
{
	double elapsedTime;

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	return (elapsedTime);
}