#include <bits/stdc++.h>
#include "instructions.cpp"
#include "map.cpp"
using namespace std;
#define ROW 7
#define COL 6
typedef pair<int,int> Pair;
typedef pair<double, pair<int, int> > pPair;
struct cell
{
	int parent_i, parent_j;
	double f, g, h;
    char t=0;
};
bool isValid(int row, int col)
{
	return (row >= 0) && (row < ROW) && (col >= 0)&& (col < COL);
}
bool isUnBlocked(int grid[][COL], int row, int col)
{
	if (grid[row][col]==1)
		return true;
	else
		return false;
}
bool isDestination(int row, int col, Pair dest)
{
	if (row == dest.first && col == dest.second)
		return true;
	else
		return false;
}
double calculateHValue(int row, int col, Pair dest)
{
	return((double)sqrt((row-dest.first)*(row-dest.first)+(col-dest.second)*(col-dest.second)));
}

void tracePath(cell cellDetails[][COL], Pair dest,string M[ROW][COL])
{
	queue<string> route;
	cout<<"\nThe Path is ";
	int row = dest.first;
	int col = dest.second;
	stack<Pair> Path;
    temp.push(0);
	while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col))
	{
		Path.push(make_pair(row,col));
        tracepath(cellDetails[row][col].t);
		int temp_row = cellDetails[row][col].parent_i;
		int temp_col = cellDetails[row][col].parent_j;
		row = temp_row;
		col = temp_col;
	}
	Path.push(make_pair(row, col));
	while (!Path.empty())
	{
		Pair p = Path.top();
		Path.pop();
		if(M[p.first][p.second]!="")
		{
			route.push(M[p.first][p.second]);
		}
		printf("-> (%d,%d) ", p.first, p.second);
	}
    cout<<endl<<endl;
	cout<<"We are taking the route..";
	while(!route.empty())
	{
		string s;
		s=route.front();
		route.pop();
		cout<<"-> "<<s;
	}
	cout<<endl<<endl;
	cout<<"Instructions: "<<endl;
	cout<<"--------------------------"<<endl;
    getins();

	return;
}
void aStarSearch(int grid[][COL], Pair src, Pair dest,string M[ROW][COL])
{
	if (!isValid(src.first, src.second))
	{
		cout<<"Source is invalid\n";
		return;
	}

	if (!isValid(dest.first, dest.second))
	{
		cout<<"Destination is invalid\n";
		return;
	}

	if (!isUnBlocked(grid, src.first, src.second) || !isUnBlocked(grid, dest.first, dest.second))
	{
		cout<<"Source or the destination is blocked\n";
		return;
	}

	if (isDestination(src.first, src.second, dest))
	{
		cout<<"We are already at the destination\n";
		return;
	}

	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));
	cell cellDetails[ROW][COL];
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			cellDetails[i][j].f = FLT_MAX;
			cellDetails[i][j].g = FLT_MAX;
			cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].t = '\0';
			cellDetails[i][j].parent_i = -1;
			cellDetails[i][j].parent_j = -1;
		}
	}
	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent_i = i;
	cellDetails[i][j].parent_j = j;

	set<pPair> openList;
	openList.insert(make_pair(0.0, make_pair(i, j)));
	bool foundDest = false;

	while (!openList.empty())
	{
		pPair p = *openList.begin();
		openList.erase(openList.begin());
		i = p.second.first;
		j = p.second.second;
		closedList[i][j] = true;
		double gNew, hNew, fNew;

		//(North)
		if (isValid(i - 1, j))
		{
			if (isDestination(i - 1, j, dest))
			{
				cellDetails[i - 1][j].parent_i = i;
				cellDetails[i - 1][j].parent_j = j;
                cellDetails[i - 1][j].t = 'u';
				cout<<"Destination set..\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i - 1][j] && isUnBlocked(grid, i - 1, j))
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i - 1, j, dest);
				fNew = gNew + hNew;
				if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i - 1, j)));
					cellDetails[i - 1][j].f = fNew;
					cellDetails[i - 1][j].g = gNew;
					cellDetails[i - 1][j].h = hNew;
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
                    cellDetails[i - 1][j].t = 'u';
				}
			}
		}

		//(South)
		if (isValid(i + 1, j))
		{
			if (isDestination(i + 1, j, dest))
			{
				cellDetails[i + 1][j].parent_i = i;
				cellDetails[i + 1][j].parent_j = j;
                cellDetails[i + 1][j].t = 'd';
				cout<<"Destination set..\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i + 1][j] && isUnBlocked(grid, i + 1, j))
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i + 1, j, dest);
				fNew = gNew + hNew;
				if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i + 1, j)));
					cellDetails[i + 1][j].f = fNew;
					cellDetails[i + 1][j].g = gNew;
					cellDetails[i + 1][j].h = hNew;
					cellDetails[i + 1][j].parent_i = i;
					cellDetails[i + 1][j].parent_j = j;
                    cellDetails[i + 1][j].t = 'd';
				}
			}
		}

		//(East)
		if (isValid(i, j + 1))
		{
			if (isDestination(i, j + 1, dest))
			{
				cellDetails[i][j + 1].parent_i = i;
				cellDetails[i][j + 1].parent_j = j;
                cellDetails[i][j + 1].t = 'r';
				cout<<"Destination set...\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i][j + 1]&& isUnBlocked(grid, i, j + 1))
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j + 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i, j + 1)));

					cellDetails[i][j + 1].f = fNew;
					cellDetails[i][j + 1].g = gNew;
					cellDetails[i][j + 1].h = hNew;
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
                    cellDetails[i][j + 1].t = 'r';
				}
			}
		}

		//(West)
		if (isValid(i, j - 1))
		{
			if (isDestination(i, j - 1, dest))
			{
				cellDetails[i][j - 1].parent_i = i;
				cellDetails[i][j - 1].parent_j = j;
                cellDetails[i][j - 1].t = 'l';
				cout<<"Destination set...\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i][j - 1] && isUnBlocked(grid, i, j - 1))
			{
				gNew = cellDetails[i][j].g + 1.0;
				hNew = calculateHValue(i, j - 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i, j - 1)));

					cellDetails[i][j - 1].f = fNew;
					cellDetails[i][j - 1].g = gNew;
					cellDetails[i][j - 1].h = hNew;
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;
                    cellDetails[i][j - 1].t = 'l';
				}
			}
		}
		//North-East
		if (isValid(i - 1, j + 1))
		{
			if (isDestination(i - 1, j + 1, dest))
			{
				cellDetails[i - 1][j + 1].parent_i = i;
				cellDetails[i - 1][j + 1].parent_j = j;
                cellDetails[i - 1][j + 1].t = 'e';
				cout<<"Destination set...\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i - 1][j + 1] && isUnBlocked(grid, i - 1, j + 1))
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i - 1, j + 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i - 1][j + 1].f == FLT_MAX || cellDetails[i - 1][j + 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i - 1, j + 1)));

					cellDetails[i - 1][j + 1].f = fNew;
					cellDetails[i - 1][j + 1].g = gNew;
					cellDetails[i - 1][j + 1].h = hNew;
					cellDetails[i - 1][j + 1].parent_i = i;
					cellDetails[i - 1][j + 1].parent_j = j;
                    cellDetails[i - 1][j + 1].t = 'e';
				}
			}
		}

		//(North-West)
		if (isValid(i - 1, j - 1) )
		{
			if (isDestination(i - 1, j - 1, dest))
			{
				cellDetails[i - 1][j - 1].parent_i = i;
				cellDetails[i - 1][j - 1].parent_j = j;
                cellDetails[i - 1][j - 1].t = 'q';
				cout<<"Destination set..\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i - 1][j - 1] && isUnBlocked(grid, i - 1, j - 1))
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i - 1, j - 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i - 1][j - 1].f == FLT_MAX || cellDetails[i - 1][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i - 1, j - 1)));
					cellDetails[i - 1][j - 1].f = fNew;
					cellDetails[i - 1][j - 1].g = gNew;
					cellDetails[i - 1][j - 1].h = hNew;
					cellDetails[i - 1][j - 1].parent_i = i;
					cellDetails[i - 1][j - 1].parent_j = j;
                    cellDetails[i - 1][j - 1].t = 'q';
				}
			}
		}

		//(South-East)
		if (isValid(i + 1, j + 1))
		{
			if (isDestination(i + 1, j + 1, dest))
			{
				cellDetails[i + 1][j + 1].parent_i = i;
				cellDetails[i + 1][j + 1].parent_j = j;
                cellDetails[i + 1][j + 1].t = 'c';
				cout<<"Destination set...\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i + 1][j + 1] && isUnBlocked(grid, i + 1, j + 1))
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i + 1, j + 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i + 1][j + 1].f == FLT_MAX || cellDetails[i + 1][j + 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i + 1, j + 1)));
					cellDetails[i + 1][j + 1].f = fNew;
					cellDetails[i + 1][j + 1].g = gNew;
					cellDetails[i + 1][j + 1].h = hNew;
					cellDetails[i + 1][j + 1].parent_i = i;
					cellDetails[i + 1][j + 1].parent_j = j;
                    cellDetails[i + 1][j + 1].t = 'c';
				}
			}
		}
		//(South-West)
		if (isValid(i + 1, j - 1))
		{
			if (isDestination(i + 1, j - 1, dest))
			{
				cellDetails[i + 1][j - 1].parent_i = i;
				cellDetails[i + 1][j - 1].parent_j = j;
                cellDetails[i + 1][j - 1].t = 'z';
				cout<<"Destination set...\n";
				tracePath(cellDetails, dest,M);
				foundDest = true;
				return;
			}
			else if (!closedList[i + 1][j - 1] && isUnBlocked(grid, i + 1, j - 1))
			{
				gNew = cellDetails[i][j].g + 1.414;
				hNew = calculateHValue(i + 1, j - 1, dest);
				fNew = gNew + hNew;
				if (cellDetails[i + 1][j - 1].f == FLT_MAX || cellDetails[i + 1][j - 1].f > fNew)
				{
					openList.insert(make_pair(fNew, make_pair(i + 1, j - 1)));
					// Update the details of this cell
					cellDetails[i + 1][j - 1].f = fNew;
					cellDetails[i + 1][j - 1].g = gNew;
					cellDetails[i + 1][j - 1].h = hNew;
					cellDetails[i + 1][j - 1].parent_i = i;
					cellDetails[i + 1][j - 1].parent_j = j;
                    cellDetails[i + 1][j - 1].t = 'z';
				}
			}
		}
	}
	if (foundDest == false)
		cout<<"Destination not found\n";

	return;
}
void initializeMap(string m[ROW][COL])
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			m[i][j]="";
		}
	}
	m[0][0]="Mall";
	m[0][2]="Hotel";
	m[0][5]="Airport";
	m[2][2]="Home";
	m[3][0]="Hospital";
	m[4][4]="School";
	m[6][0]="Bus Stop";
	m[6][5]="Railway Station";
}
void navigation()
{
	int grid[ROW][COL]
		= { { 1, 0, 1, 0, 1, 1},
			{ 1, 0, 1, 0, 1, 0},
			{ 1, 1, 1, 1, 1, 1},
			{ 1, 0, 0, 1, 0, 1},
			{ 1, 1, 1, 1, 1, 1},
			{ 1, 0, 0, 0, 0, 1},
			{ 1, 0, 0, 0, 0, 1}};
	string MAP[ROW][COL];
	initializeMap(MAP);
	int sr,sc,dr,dc;
	int ch;
	cout<<endl<<"Choose current location: "<<endl<<endl;
	cout<<"1.Home\n2.Mall\n3.Airport\n4.Hospital\n5.PSG Tech\n6.Bus Stop\n7.Railway Station\n8.Hotel\n9.School"<<endl;
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:sr=2,sc=2;break;
		case 2:sr=0,sc=0;break;
		case 3:sr=0,sc=5;break;
		case 4:sr=3,sc=0;break;
		case 5:sr=2,sc=4;break;
		case 6:sr=6,sc=0;break;
		case 7:sr=6,sc=5;break;
		case 8:sr=0,sc=2;break;
		case 9:sr=4,sc=4;break;
	}
	cout<<endl<<"Choose destination: "<<endl<<endl;
	cout<<"1.Home\n2.Mall\n3.Airport\n4.Hospital\n5.PSG Tech\n6.Bus Stop\n7.Railway Station\n8.Hotel\n9.School"<<endl;
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:dr=2,dc=2;break;
		case 2:dr=0,dc=0;break;
		case 3:dr=0,dc=5;break;
		case 4:dr=3,dc=0;break;
		case 5:dr=2,dc=4;break;
		case 6:dr=6,dc=0;break;
		case 7:dr=6,dc=5;break;
		case 8:dr=0,dc=2;break;
		case 9:dr=4,dc=4;break;
	}
	Pair src=make_pair(sr,sc);
	Pair dest=make_pair(dr,dc);
	aStarSearch(grid, src, dest,MAP);
	display(instruct);
	generatemap();
}
