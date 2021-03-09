#include "blur_filter.h"
#include "inversion_filter.h"
#include "gray_filter.h"
#include "gaussian_filter.h"

std::string type2str(int type) {
  std::string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

int main() {
	cv::Mat img = cv::imread("C:\\Users\\arryo\\Pictures\\unn.png");
    gaussian_filter fil(2, 2, img);
	cv::Mat res_img = fil.make();
	cv::imshow("inversion filter", res_img);
	cv::waitKey(0);

}