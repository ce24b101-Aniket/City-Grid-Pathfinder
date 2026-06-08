#include<bits/stdc++.h>
using namespace std;

// Coordinate structure
struct Point {
    int x, y;
};

class CityGridNavigator {
private:
    int rows, cols;
    vector<vector<int>> grid; // 0: Path, 1: Obstacle
    
    // Directions: Up, Down, Left, Right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

public:
    CityGridNavigator(vector<vector<int>>& inputGrid) {
        grid = inputGrid;
        rows = grid.size();
        cols = grid[0].size();
    }

    bool isValid(int r, int c, vector<vector<bool>>& visited) {
        return (r >= 0 && r < rows && c >= 0 && c < cols && 
                grid[r][c] == 0 && !visited[r][c]);
    }

    void findShortestPath(Point start, Point end) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<Point>> parent(rows, vector<Point>(cols, {-1, -1}));
        
        queue<Point> q;
        q.push(start);
        visited[start.x][start.y] = true;

        bool reached = false;
        while (!q.empty()) {
            Point curr = q.front();
            q.pop();

            if (curr.x == end.x && curr.y == end.y) {
                reached = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                if (isValid(nx, ny, visited)) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = curr;
                    q.push({nx, ny});
                }
            }
        }

        displayResult(reached, parent, start, end);
    }

    void displayResult(bool reached, vector<vector<Point>>& parent, Point start, Point end) {
        if (!reached) {
            cout << "No feasible path found for the machinery." << endl;
            return;
        }

        // Trace back path
        vector<vector<char>> visualGrid(rows, vector<char>(cols, '.'));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) if(grid[i][j] == 1) visualGrid[i][j] = '#';
        }

        Point curr = end;
        while (curr.x != -1) {
            visualGrid[curr.x][curr.y] = '*';
            curr = parent[curr.x][curr.y];
        }
        visualGrid[start.x][start.y] = 'S';
        visualGrid[end.x][end.y] = 'E';

        cout << "\n--- Optimized Construction Site Logistics ---\n";
        cout << "(S: Start, E: Depot, #: Obstacle, *: Path)\n\n";
        for (auto row : visualGrid) {
            for (char cell : row) cout << cell << " ";
            cout << endl;
        }
    }
};

int main() {
    // 0 = Clear ground, 1 = Material piles/Buildings
    vector<vector<int>> siteMap = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}
    };

    CityGridNavigator navigator(siteMap);
    navigator.findShortestPath({0, 0}, {4, 4});

    return 0;
}