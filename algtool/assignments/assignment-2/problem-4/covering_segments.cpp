// Copyright 2016, Konstantin Pachuev
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <limits>

using std::vector;

struct Segment {
  uint32_t start, end;
};

// Finds segment with min right endpoint.
size_t find_segment(const vector<Segment> &segments) {
  size_t seg_i = 0;
  uint32_t min = std::numeric_limits<uint32_t>::max();
  for (int i = 0; i < segments.size(); ++i) {
    if ( segments[i].end < min ) {
      min = segments[i].end;
      seg_i = i;
    }
  }
  return seg_i;
}

vector<uint32_t> optimal_points(vector<Segment>  segments) {
  size_t k;
  vector<uint32_t> points;
  while ( segments.size() > 0 ) {
    k = find_segment(segments);
    uint32_t point = segments[k].end;
    points.push_back(point);
    segments.erase(segments.begin() + k);
    auto it = segments.begin();
    // Removes segments covering point
    while (it != segments.end()) {
      if ( it->start <= point && point <= it->end ) {
            it = segments.erase(it);
        } else {
           ++it;
        }
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  if ( n < 1 || 1000 < n )
    return 0;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    uint32_t start, end;
    std::cin >> start >> end;
    if ( start > 1000000000 )
      return 0;
    if ( end > 1000000000 )
      return 0;
    segments[i].start = start;
    segments[i].end = end;
  }
  vector<uint32_t> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
