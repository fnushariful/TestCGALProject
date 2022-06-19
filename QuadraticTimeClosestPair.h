//
// Created by Ghosh, Anirban on 1/19/22.
//

#ifndef CODE_QUADRATICTIMECLOSESTPAIR_H
#define CODE_QUADRATICTIMECLOSESTPAIR_H

#include <utility>
#include "CGALComponents.h"

std::pair<unsigned, unsigned> findClosestPairQuadratic(const std::vector<Point> &P) {
    double minDistanceSoFar = INFINITY;
    unsigned p, q;

    for (unsigned i = 0; i < P.size(); ++i)
        for (unsigned j = i + 1; j < P.size() - 1; ++j) {
            double d = CGAL::squared_distance(P[i], P[j]); // returns squared distance
            if (d < minDistanceSoFar) {
                p = i;
                q = j;
                minDistanceSoFar = d;
            }
        }

    return std::make_pair(p, q);
}

#endif //CODE_QUADRATICTIMECLOSESTPAIR_H
