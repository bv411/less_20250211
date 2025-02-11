//#include <iostream>
//
//using namespace std;
//
//#define MAXNUM 10
//#define START   0
//#define FINISH  2
//
//int isSolved(int arr[], int n) {
//    for (int i = 0; i < n; ++i) {
//        if (arr[i] != FINISH) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int isOdd(int x) {
//    return ((x % 2) == 1);
//}
//
//int main_() {
//
//    const int numberOfDisks = 2;
//
//    int rod[numberOfDisks];
//    for (int i = 0; i < numberOfDisks; ++i) {
//        rod[i] = START;
//    }
//    int smallestDir = (isOdd(numberOfDisks)) ? -1 : 1;
//    int alternateRodTable[3][2] = { {1, 2}, {0, 2}, {0, 1} };
//
//    int moveCount = 0;
//    do {
//        ++moveCount;
//
//        int disk, rodFrom, rodTo;
//        if (isOdd(moveCount)) {
//            // move smallest disk
//            disk = 0;
//            rodFrom = rod[disk];
//            rodTo = rodFrom + smallestDir;
//            if (rodTo < START) {
//                rodTo = FINISH;
//            }
//            if (rodTo > FINISH) {
//                rodTo = START;
//            }
//        }
//        else {
//            // move alternate disk
//            // determine which disk is at the top of each rod
//            // set default value (empty rod) to greater than the largest disk
//            int topDisk[3] = { numberOfDisks, numberOfDisks, numberOfDisks };
//            // stack each disk on its respective rod
//            // smaller disks overwrite larger disks
//            for (int i = numberOfDisks - 1; i > -1; --i) {
//                topDisk[rod[i]] = i;
//            }
//            // select the two rods which do not involve the smallest disk
//            rodFrom = alternateRodTable[rod[0]][0];
//            rodTo = alternateRodTable[rod[0]][1];
//            // check which of the two possible "From => To" moves is valid
//            if (topDisk[rodFrom] > topDisk[rodTo]) {
//                swap(rodFrom, rodTo);
//            }
//            disk = topDisk[rodFrom];
//        }
//        rod[disk] = rodTo;
//
//        cout << "Move disk " << disk + 1 << " from " << rodFrom + 1 << " to " << rodTo + 1 << endl;
//
//    } while (!isSolved(rod, numberOfDisks));
//
//    return 0;
//}
//
//
