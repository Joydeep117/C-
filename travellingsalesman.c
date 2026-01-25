#include <stdio.h>
#include <limits.h>

#define N 4   // Number of cities

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int VISITED_ALL = (1 << N) - 1;
int dp[1 << N][N];

// Function to find minimum cost using DP
int tsp(int mask, int pos) {
    // If all cities are visited, return cost to go back to starting city
    if (mask == VISITED_ALL)
        return dist[pos][0];

    // If already calculated
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try visiting all unvisited cities
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Initialize DP table
    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    printf("Minimum travelling cost = %d\n", tsp(1, 0));
    return 0;
}
