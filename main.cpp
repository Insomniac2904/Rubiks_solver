#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

class RubiksCubeBitboard;
struct HashBitboard;
using namespace std;
using namespace std::chrono;
int main() {

    string fileName = "/home/adarsh/Desktop/Rubiks_solver-main/Database/cornerDepth5V1.txt";
    RubiksCube3dArray object3DArray;

    // Shuffle the cube
    vector<RubiksCube::MOVE> shuffle_moves = object3DArray.randomShuffleCube(6);
    cout << "AFTER SHUFFLING THE CUBE 6 TIMES:\n";
    object3DArray.print();

    cout << "SHUFFLE MOVES OF THE CUBE: ";
    for (auto move : shuffle_moves) cout << object3DArray.getMove(move) << " ";
    cout << "\n";

    // DFS Solver
    auto start = high_resolution_clock::now();
    DFSSolver<RubiksCube3dArray, Hash3d> dfs_solver(object3DArray, 7);
    vector<RubiksCube::MOVE> dfs_moves = dfs_solver.solve();
    auto stop = high_resolution_clock::now();
    auto dfs_time = duration_cast<milliseconds>(stop - start).count();

    cout << "DFS OUTPUT:\n";
    dfs_solver.rubiksCube.print();
    cout << "DFS MOVES: ";
    for (auto move : dfs_moves) cout << object3DArray.getMove(move) << " ";
    cout << "\nTime Taken (ms): " << dfs_time << "\n";

    // IDDFS Solver
    start = high_resolution_clock::now();
    IDDFSSolver<RubiksCube3dArray, Hash3d> iddfs_solver(object3DArray, 7);
    vector<RubiksCube::MOVE> iddfs_moves = iddfs_solver.solve();
    stop = high_resolution_clock::now();
    auto iddfs_time = duration_cast<milliseconds>(stop - start).count();

    cout << "IDDFS OUTPUT:\n";
    iddfs_solver.rubiksCube.print();
    cout << "IDDFS MOVES: ";
    for (auto move : iddfs_moves) cout << object3DArray.getMove(move) << " ";
    cout << "\nTime Taken (ms): " << iddfs_time << "\n";

    // IDA* Solver
    start = high_resolution_clock::now();
    IDAstarSolver<RubiksCube3dArray, Hash3d> ida_solver(object3DArray, fileName);
    vector<RubiksCube::MOVE> ida_moves = ida_solver.solve();
    stop = high_resolution_clock::now();
    auto ida_time = duration_cast<milliseconds>(stop - start).count();

    cout << "IDA* OUTPUT:\n";
    ida_solver.rubiksCube.print();
    cout << "IDA* MOVES: ";
    for (auto move : ida_moves) cout << object3DArray.getMove(move) << " ";
    cout << "\nTime Taken (ms): " << ida_time << "\n";



    // ==========================================================================================
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();

    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube, fileName);
    //
    // vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // idAstarSolver.rubiksCube.print();


    // RubiksCube3dArray object3DArray;
    // // // RubiksCube1dArray object1dArray;
    // //
    // // object3DArray.print();
    // vector<RubiksCube::MOVE>shuffle = object3DArray.randomShuffleCube((6));
    //
    // cout<<"AFTER SHUFFLING THE CUBE 6 TIMES: \n";
    // object3DArray.print();
    // cout<<"SHUFFLE MOVES THE CUBE ARE: \n";
    // for(auto move:shuffle) cout<<object3DArray.getMove(move)<<" ";
    // cout<<"\n";
    // cout<<"INITIATING DFS SOVLER WITH MAX DEPTH OF 4: \n";
    // DFSSolver<RubiksCube3dArray,Hash3d>dfs_solver(object3DArray,4);
    // vector<RubiksCube::MOVE>dfsMoves = dfs_solver.solve();
    // cout<<"DFS SOVLER OUTPUT: \n";
    // dfs_solver.rubiksCube.print();
    // cout<<"MOVES FOUND BY DFS SOLVER: \n";
    // for(auto move:dfsMoves) cout<<object3DArray.getMove(move)<<" ";
    // cout<<"\n";
    // // RubiksCubeBitboard cube;
    // // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
    //
    // for(auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();

    // object3DArray.print();
    // vector<RubiksCube::MOVE>shuffledMove =  object3DArray.randomShuffleCube(3);
    // for(auto move:shuffledMove)
    // {
    //     cout<<object3DArray.getMove(move)<<" ";
    // }
    // cout<<"\n ====================== \n";
    // object3DArray.print();
    //
    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";

    // if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";

    // if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";

    // objectBitboard.u();
    // object3DArray.u();
    // object1dArray.u();
    // objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();

//    objectBitboard.l();
//    object3DArray.l();
//    object1dArray.l();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.f();
//    object3DArray.f();
//    object1dArray.f();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.r();
//    object3DArray.r();
//    object1dArray.r();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.b();
//    object3DArray.b();
//    object1dArray.b();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.d();
//    object3DArray.d();
//    object1dArray.d();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    objectBitboard.dPrime();
//    object3DArray.dPrime();
//    object1dArray.dPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.bPrime();
//    object3DArray.bPrime();
//    object1dArray.bPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.rPrime();
//    object3DArray.rPrime();
//    object1dArray.rPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.fPrime();
//    object3DArray.fPrime();
//    object1dArray.fPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.lPrime();
//    object3DArray.lPrime();
//    object1dArray.lPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    objectBitboard.uPrime();
//    object3DArray.uPrime();
//    object1dArray.uPrime();
//    objectBitboard.print();
//    object3DArray.print();
//    object1dArray.print();
//
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";

    // Create two Cubes ------------------------------------------------------------------------------------------

//    RubiksCube3dArray cube1;
//    RubiksCube3dArray cube2;

//    RubiksCube1dArray cube1;
//    RubiksCube1dArray cube2;

//    RubiksCubeBitboard cube1;
//    RubiksCubeBitboard cube2;


//  Equality and assignment of cubes --------------------------------------------------------------------------

//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";
//
//    cube1.randomShuffleCube(1);
//
//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";
//
//    cube2 = cube1;
//
//    if(cube1 == cube2) cout << "Is equal\n";
//    else cout << "Not Equal\n";


//  Unordered_map of Cubes  ------------------------------------------------------------------------------------


//    unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;

//    unordered_map<RubiksCube1dArray, bool, Hash1d> mp1;

//    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
//
//    mp1[cube1] = true;
//    cube2.randomShuffleCube(8);
//    if (mp1[cube1]) cout << "Cube1 is present\n";
//    else cout << "Cube1 is not present\n";
//
//    if (mp1[cube2]) cout << "Cube2 is present\n";
//    else cout << "Cube2 is not present\n";
//

// DFS Solver Testing __________________________________________________________________________________________
//    RubiksCube3dArray cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
//    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    dfsSolver.rubiksCube.print();


//BFS Solver -----------------------------------------------------------------------------------------------------
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
//    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
//
//    for(auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    bfsSolver.rubiksCube.print();

// IDDFS Solver ----------------------------------------------------------------------------------------------------
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 7);
//    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    iddfsSolver.rubiksCube.print();

// IDA* SOLVER ---------------------------------------------------------------------------------------------------
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // idAstarSolver.rubiksCube.print();

// CornerPatternDatabase Testing ---------------------------------------------------------------------------------

//    CornerPatternDatabase cornerDB;
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 5);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cube.randomShuffleCube(1);
//    cube.print();
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";
//
//    cornerDB.setNumMoves(cube, 6);
//
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";


// CornerDBMaker Testing --------------------------------------------------------------------------
    // string fileName = "C:\\Users\\user\\CLionProjects\\rubiks-cube-solver\\Databases\\cornerDepth5V1.txt";

    //    Code to create Corner Database
    //    CornerDBMaker dbMaker(fileName, 0x99);
    //    dbMaker.bfsAndStore();

    // RubiksCubeBitboard cube;
    // auto shuffleMoves = cube.randomShuffleCube(13);
    // cube.print();
    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    //
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    // auto moves = idaStarSolver.solve();
    //
    // idaStarSolver.rubiksCube.print();
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";


    return 0;
}
