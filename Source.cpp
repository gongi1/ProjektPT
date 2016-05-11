
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>

///////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	cv::VideoCapture capWebcam(0);		

	if (capWebcam.isOpened() == false) {			
		std::cout << "error: capWebcam not accessed successfully\n\n";	
		return(0);														
	}

	cv::Mat imgOriginal;		
	cv::Mat imgGrayscale;		
	cv::Mat imgBlurred;			
	cv::Mat imgCanny;			

	char charCheckForEscKey = 0;

	while (charCheckForEscKey != 27 && capWebcam.isOpened()) {		
		bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);		

		if (!blnFrameReadSuccessfully || imgOriginal.empty()) {		
			std::cout << "error: frame not read from webcam\n";		
			break;													
		}

		cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);		

		cv::GaussianBlur(imgGrayscale,			
			imgBlurred,							
			cv::Size(5, 5),						
			1.8);								

		cv::Canny(imgBlurred,			
			imgCanny,					
			50,							
			100);						

										
		cv::namedWindow("imgOriginal", CV_WINDOW_NORMAL);	
		cv::namedWindow("imgCanny", CV_WINDOW_NORMAL);		
															
		cv::imshow("imgOriginal", imgOriginal);		
		cv::imshow("imgCanny", imgCanny);

		charCheckForEscKey = cv::waitKey(1);		
	}	

	return(0);
}