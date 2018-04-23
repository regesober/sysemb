#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void laplacian_filtering(unsigned char image1[10][10], unsigned char image2[10][10], int x_size1, int y_size1, int x_size2, int y_size2)
     /* Spatial filtering of image data */
     /* 8-neighbor Laplacian filter */
     /* Input: image1[y][x] ---- Outout: image2[y][x] */
{
  /* Definition of 8-neighbor Laplacian filter */
  int weight[3][3] = {{ 1,  1,  1 },
		      { 1,  -8,  1 },
		      { 1,  1,  1 }};
  double pixel_value;
  double min, max;
  int x, y, i, j;  /* Loop variable */
  
  /* Maximum values calculation after filtering*/
  //printf("Now, filtering of input image is performed\n\n");
  min = DBL_MAX;
  max = -DBL_MAX;
  for (y = 1; y < y_size1 - 1; y++) {
    for (x = 1; x < x_size1 - 1; x++) {
      pixel_value = 0.0;
      for (j = - 1; j < 2; j++) {
	    for (i = -1; i < 2; i++) {
	      pixel_value += weight[j + 1][i + 1] * image1[y + j][x + i];
	    }
      }
      if (pixel_value < min) min = pixel_value;
      if (pixel_value > max) max = pixel_value;
    }
  }
  //if ((int)(max - min) == 0) {
    //printf("Nothing exists!!!\n\n");
    //exit(1);
  //}

  /* Initialization of image2[y][x] */
  x_size2 = x_size1;
  y_size2 = y_size1;
  for (y = 0; y < y_size2; y++) {
    for (x = 0; x < x_size2; x++) {
      image2[y][x] = 0;
    }
  }
  
  /* Generation of image2 after linear transformtion */
  for (y = 1; y < y_size1 - 1; y++) {
    for (x = 1; x < x_size1 - 1; x++) {
      pixel_value = 0.0;
      for (j = - 1; j < 2; j++) {
	    for (i = -1; i < 2; i++) {
	      pixel_value += weight[j + 1][i + 1] * image1[y + j][x + i];
	    }
      }
      pixel_value = 255 * (pixel_value - min) / (max - min);
      image2[y][x] = (unsigned char)pixel_value;
    }
  }
}

int main( )
{
  unsigned char image1[10][10];
  unsigned char image2[10][10];
  laplacian_filtering(image1, image2, 10, 10, 10, 10); /* Laplacian filtering is applied to image1 */
  
  return 0;
}
