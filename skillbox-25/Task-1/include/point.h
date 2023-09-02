#pragma once

struct point{
    double x_cord = 0;
    double y_cord = 0;
};

point get_new_point();

void print_point(point pnt);

bool compare_points(point first, point second);