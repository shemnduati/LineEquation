/// @file pa04.cpp
/// @author Dr. Brodersen <david.brodersen@csn.edu>
/// @date 10/5/22
/// @note I pledge my word of honor that I have abided by the
/// the CSN Academic Integrity Policy while completing this assignment.
///
/// @brief This program reads in two Cartesian coordinates representing two
/// points on a line, then computes the line equation, slope direction, and
/// line segment length between the two points. If the points are the same,
/// an error is reported. If the input is bad, an error is reported.
/// On error, a usage message is presented.
///
/// @note People who helped me:
///
/// @note This is but one possible solution to the assignment.
///       Programming techniques and commands in this solution
///       are aligned with the current and previous chapters,
///       labs, and lectures, which may result in a trade-off
///       between efficient coding and what student are
///       currently able to understand.

// include header files
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

// set namespace
using namespace std;

/// -------------------------------------------------------------------------
/// Main entry-point for this application
///
/// @returns Exit-code for the process - 0 for success, else an error code.
/// -------------------------------------------------------------------------
int main() {

    // Variable declarations(s)
    int exitState;              // tracks the exit code for the process
    exitState = EXIT_FAILURE;   // set state to failed run

    double x1;                  // x coordinate of point 1
    double y1;                  // y coordinate of point 1
    double x2;                  // x coordinate of point 2
    double y2;                  // y coordinate of point 2
    string eMessage;            // error message


    /* ******* read and process input ************************************* */
    // read and process input
    // no prompt to user: using linux echo command for input
    //                          echo 1 2 3 4 | pa04
    if (cin >> x1 >> y1 >> x2 >> y2) {

        // block constant definitions for this code block
        const int VERT = 0;         // signals slope is vertical
        const int HORZ = 1;         // signals slope is horizontal
        const int INCR = 2;         // signals slope is increasing
        const int DECR = 3;         // signals slope is decreasing
        const int CW   = 21;        // output label column width

        // zero threshold: anything smaller than this number is considered zero
        const double LIMIT = 0.0000001;

        // block variable declarations for this code block:
        // some are initialized to silence compiler / linter warnings
        int    direction = VERT;    // slope direction, init vert
        double slope     = 0;       // computed slope value (m)
        double intercept = 0;       // computed y-intercept value
        double dx;                  // change in x (the "run")
        double dy;                  // change in y (the "rise")
        double length;              // line segment length

        /* ******* processing phase *************************************** */
        // check for same point
        if (fabs((fabs(x1) - fabs(x2))) < LIMIT &&
            fabs((fabs(y1) - fabs(y2))) < LIMIT) {

            // set the error message to points the same message
            eMessage = "Error, the points are the same. Please try again.";

            exitState = EXIT_FAILURE;        // program unsuccessful
        } else {
            dx = x2 - x1;               // calculate change in x
            dy = y2 - y1;               // calculate change in y

            // distance between pts
            length = sqrt(dx * dx + dy * dy);

            // avoid division by zero
            // changing to absolute value avoides testing
            // a floating point number for equality
            // since direction is defaulted to VERT a failed test will
            // leave direction set to VERT
            if (fabs(dx) > LIMIT) {
                // calculate the slope of the line
                slope       = dy / dx;

                // calculate the y-intercept(b)
                intercept   = y1 - slope * x1;

                if (slope > 0) {
                    direction = INCR;
                } else if (slope < 0) {
                    direction = DECR;
                } else {
                    direction = HORZ;
                }
                // optional
                // direction = (slope < 0) ? DECR : (slope > 0) ? INCR : HORZ;

                exitState = EXIT_SUCCESS;        // program successful
            }

            /* ******* output phase *************************************** */
            cout << left;                     // configure stream

            // output the line equation
            cout << "From point: (" << x1 << ", " << y1 << ") to point: ("
            << x2 << ", " << y2 << ")." << "\n";
            cout << setw(CW) << "Line equation:";
            if (direction == VERT) {
                cout << "x = " << x1 << '\n';
            } else if (direction == HORZ) {
                cout << "y = " << y1 << '\n';
            } else {
                cout << "y = " << slope << "x + " << intercept << '\n';
            }

            // output the slope direction
            cout << setw(CW) << "Slope direction:";
            switch (direction) {
                case VERT:  cout << "vertical"  ;  break;
                case HORZ:  cout << "horizontal";  break;
                case INCR:  cout << "increasing";  break;
                case DECR:  cout << "decreasing";  break;
                default:    cout << "undefined" ;  break;
            }
            cout << endl;

            // output the segment length
            cout << setw(CW) << "Line segment length:" << length << endl;
        }
    } else {
        // set the error message to input fail message
        eMessage = "Error reading input. Please try again.";
    }
    if (exitState == EXIT_FAILURE) {
        cerr << eMessage << endl;
    }

    cout << endl;
    return exitState;
}


// EOF: pa04.cpp