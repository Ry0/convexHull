// #include <opencv2/core.hpp>
#include <opencv/cv.h>
// #include <opencv2/imgcodecs.hpp>
// #include <opencv2/highgui.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string &input, char delimiter) {
  istringstream stream(input);
  string field;
  vector<string> result;
  while (getline(stream, field, delimiter)) {
    result.push_back(field);
  }
  return result;
}

void readCSV(string filename, vector<cv::Point2f> points) {
  ifstream ifs(filename);
  string line;
  while (getline(ifs, line)) {
    vector<string> strvec = split(line, ',');
    for (int i = 0; i < 2; i++) {
      // printf("%5lf\n", stod(strvec.at(i)));
      cv::Point2f pt;
      pt.x = stod(strvec.at(i));
      pt.y = stod(strvec.at(i));
      points.push_back(pt);
    }
  }
}

void writeCSV(string filename, vector<cv::Point2f> points){
  std::ofstream data(filename);
  for (size_t i = 0; i < points.size(); ++i)
  {
    data << points[i].x << "," << points[i].y << endl;
  }
}

int main(int argc, const char **argv) {
  vector<cv::Point2f> contour;
  ifstream ifs("input.csv");
  string line;
  while (getline(ifs, line)) {
    vector<string> strvec = split(line, ',');
    cv::Point2f pt;
    pt.x = stod(strvec.at(0));
    pt.y = stod(strvec.at(1));
    contour.push_back(pt);
  }
  cout << "------------------input data----------------------" << endl;
  for (std::vector<cv::Point2f>::iterator i = contour.begin(); i != contour.end(); ++i) {
    cout << i->x << ", " << i->y << endl;
  }

  vector<cv::Point2f> hull;
  cv::convexHull(contour, hull);
  cout << "------------------convex hull data----------------------" << endl;
  for (std::vector<cv::Point2f>::iterator i = hull.begin(); i != hull.end();
       ++i) {
    cout << i->x << ", " << i->y << endl;
  }

  vector<cv::Point2f> approx;
  approxPolyDP(hull, approx, 0.000001, true);

  double length = arcLength(hull, true);
  double area = contourArea(hull);

  cout << "length = " << length << endl << "area = " << area << endl
       << "approx poly vertices = " << approx.size() << endl;
  double circle_level = 4.0 * CV_PI * area / (length * length);
  cout << "circle level = " << circle_level << endl;

  writeCSV("out.csv", approx);

  return 0;
}