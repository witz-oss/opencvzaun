#include <iostream>
#include <opencv2/opencv.hpp>
#define PI 3.14
#define PathZaun "../cmake-build-debug/resources/Zaun.png"
#define PathMorphology "../cmake-build-debug/resources/Morphology.png"
#define PathGut_Reisen "../cmake-build-debug/resources/Gut_Reisen.png"

int main() {

    // ========================================== TASK_1 ======================================================== //

    cv::Mat img_task_1 = cv::imread(PathZaun);
    if(img_task_1.empty())
    {
        std::cout << "Could not open or find the frame" << std::endl;
        return -1 ;
    }
    cv::Mat img_gray_task_1;
    cv::cvtColor(img_task_1, img_gray_task_1, cv::COLOR_BGR2GRAY);
    cv::Mat img_canny_task_1;
    cv::Canny(img_gray_task_1, img_canny_task_1, 150, 300);
    cv::Mat img_output_task_1 = img_gray_task_1.clone();

    int diag = (int)std::hypot(img_canny_task_1.cols, img_canny_task_1.rows);
    cv::Mat AccMatArray_task_1 = cv::Mat::zeros(180, 2*diag+1, CV_32F);

    for (int i = 0; i < img_canny_task_1.cols-1; i++)
        for (int j = 0; j < img_canny_task_1.rows-1; j++)
            if(img_canny_task_1.at<uchar>(i, j) == 255)
                for(int theta = 0; theta < 180; ++theta) {
                    int d = (int) round( i * cos( ((90 - theta) * PI) / 180) + j * sin( ((90 - theta) * PI) / 180) );
                    if(d >= 0)
                        AccMatArray_task_1.at<int>(theta, d)++;
                }


    int highArray[5][2];
    for(auto & x : highArray){
        int big = 0;
        for(int i = 0; i < AccMatArray_task_1.rows; i++)
            for(int d = 0; d < AccMatArray_task_1.cols; d++)
                if(big < AccMatArray_task_1.at<int>(i, d)){
                    big = AccMatArray_task_1.at<int>(i, d);
                    x[0] = i;
                    x[1] = d;
                }
        AccMatArray_task_1.at<int>(x[0],x[1]) = 0;
    }

    for(auto & i : highArray){
        int y = (int) ( (i[1] - 0 * cos(i[0]*PI/180)) * (1/sin(i[0]*PI/180)) );
        int z = (int) ( (i[1] - (img_task_1.cols-1) * cos(i[0]*PI/180)) * (1/sin(i[0]*PI/180)) );
        cv::line(img_output_task_1, cv::Point(0, y), cv::Point(img_task_1.cols-1, z), cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
    }


    cv::namedWindow("img_canny_task_1", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_canny_task_1", img_canny_task_1);
    cv::namedWindow("img_output_task_1", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_output_task_1", img_output_task_1);
    cv::namedWindow("AccMatArray_task_1", cv::WINDOW_AUTOSIZE);
    cv::imshow("AccMatArray_task_1", AccMatArray_task_1);
    cv::waitKey(0);

    // ========================================== TASK_2 ======================================================== //

    cv::Mat img_task_2 = cv::imread(PathMorphology);
    cv::Mat img_dst_task_2 = img_task_2.clone();

    cv::dilate(img_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);

    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);

    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);


    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);

    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);

    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);


    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_dst_task_2, img_dst_task_2, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);

    cv::namedWindow("img_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_2", img_task_2);
    cv::namedWindow("img_dst_task_2", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_dst_task_2", img_dst_task_2);
    cv::waitKey(0);


    // ========================================== TASK_3 ======================================================== //

    cv::Mat img_task_3 = cv::imread(PathGut_Reisen);
    cv::Mat img_gray_task_3;

    cv::cvtColor(img_task_3, img_gray_task_3, cv::COLOR_BGR2GRAY);

    for(int i = 0; i < img_gray_task_3.rows; ++i)
        for(int j = 0; j < img_gray_task_3.cols; ++j)
            if(img_gray_task_3.at<uchar>(i, j) < 254)
                img_gray_task_3.at<uchar>(i, j) = 0;

    cv::dilate(img_gray_task_3, img_gray_task_3, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_gray_task_3, img_gray_task_3, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::dilate(img_gray_task_3, img_gray_task_3, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_gray_task_3, img_gray_task_3, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_gray_task_3, img_gray_task_3, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);
    cv::erode(img_gray_task_3, img_gray_task_3, cv::Mat(), cv::Point(-1, -1), 2, 1, 1);


    cv::namedWindow("img_task_3", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_task_3", img_task_3);
    cv::namedWindow("img_gray_task_3", cv::WINDOW_AUTOSIZE);
    cv::imshow("img_gray_task_3", img_gray_task_3);
    cv::waitKey(0);


    return 0;
}