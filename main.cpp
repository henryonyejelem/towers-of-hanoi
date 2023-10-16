#include <iostream>
using namespace std;

#include <string>

//Towers of Hanoi Homework 

void towers_of_hanoi_helper(int disk, int s, int d, int a1, int a2, int a3, int a4, int &count);
void towers_of_hanoi_helper(int disk, int s, int d, int a1, int a2, int a3, int a4, int &count);
void towers_of_hanoi(int disk, int s, int a1, int a2, int a3, int d, int &count);
void solution_towers_of_hanoi(int disk, int s, int d, int a1, int a2, int a3, int a4, int &count);

//----------------------------------------------------------------------------------
//This Section of The Program moves all Disks from S to A4
//This function is used to move around the cycle created by A1->A2->A3->A4
//We move n-1 from the start to dest, then move the bottom disk right before dest, we the move n-1 to start since the cycle lets us do so
//Then we move the bottom Disk to Dest and eventually move n-1 disks to dest
void towers_of_hanoi_helper_A(int disk, int s, int a, int d, int b, int &count){
    if(disk == 0){
        return;
    }

    else{
        towers_of_hanoi_helper_A(disk-1, s, a, d, b, count);   //n-1 disk moved from start to dest
        cout << count++ << ": Move Disk " << disk << " from A" << s-2 << " -> A" << a-2 << endl;     
        towers_of_hanoi_helper_A(disk-1, d, b, s, a, count);   //n-1 disk moved from dest to start
        cout << count++ << ": Move Disk " << disk << " from A" << a-2 << " -> A" << d-2 << endl; 
        towers_of_hanoi_helper_A(disk-1, s, a, d, b, count);   //n-1 disks moved from start back to dest
    }
}
//Start Here we move n-1 disks from S->A4, Then move The Bottom Disk S->D->A1->A2->A3
//We then move n-1 disks from A4->A2 using the function towers_of_hanoi_helper_A
void towers_of_hanoi_helper(int disk, int s, int d, int a1, int a2, int a3, int a4, int &count){
    if(disk == 0){
        return;
    }

    else{
        towers_of_hanoi_helper(disk-1, s, d, a1, a2, a3, a4, count);          //n-1 disks from S->A4
        cout << count++ << ": Move Disk " << disk << " from S -> Dest" << endl;
        cout << count++ << ": Move Disk " << disk << " from Dest -> A1" << endl;
        cout << count++ << ": Move Disk " << disk << " from A1 -> A2" << endl;
        cout << count++ << ": Move Disk " << disk << " from A2 -> A3" << endl;
        towers_of_hanoi_helper_A(disk-1, a4, a1, a2, a3, count);             //n-1 disks from A4->A2
        cout << count++ << ": Move Disk " << disk << " from A3 -> A4" << endl;
        cout << "-----------------------------------------------" << endl;
        towers_of_hanoi_helper_A(disk-1, a2, a3, a4, a1, count);             //n-1 disks from A2->A4

    }
}

//This Section of The Program moves all Disks from A4 to D
//-----------------------------------------------------------------------------------
//We use towers_of_hanoi_helper_A function to move n-1 disks to A2 from A4, then move the bottom disk to D. Then places n-1 disks back to A4 
//and continue process for subsequent disks
void towers_of_hanoi(int disk, int s, int d, int a1, int a2, int a3, int a4, int &count){
    if(disk == 0){
        return;
    }

    else{
        towers_of_hanoi_helper_A(disk-1, a4, a1, a2, a3, count);
        cout << count++ << ": Move Disk " << disk << " from A4 -> A1" << endl; 
        cout << count++ << ": Move Disk " << disk << " from A1 -> Dest" << endl; 
        towers_of_hanoi_helper_A(disk-1, a2, a3, a4, a1, count);
        cout << "-----------------------------------------------" << endl;        
        towers_of_hanoi(disk-1, s, d, a1, a2, a3, a4, count);     
    }
}

//This Part Merges Both Algorithms 
void solution_towers_of_hanoi(int disk, int s, int d, int a1, int a2, int a3, int a4, int &count){
    towers_of_hanoi_helper(disk, s, d, a1, a2, a3, a4, count); //Moves Disks to A4 from S
    towers_of_hanoi(disk, s, d, a1, a2, a3, a4, count); //Moves Disk to D from A4

}
int main(){
    int n = 10;
    int count = 1;

    solution_towers_of_hanoi(n, 1, 2, 3, 4, 5, 6, count);   
    
    return 0;
}
