/**/

//Checking for first queen in all 8 directions from the king

class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        int i, j;
        j = king[1] - 1;
        i = king[0];
        vector<vector<int>> res;
        //row left
        while (j >= 0)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            j--;
        }
        //row right
        j = king[1] + 1;
        while (j < 8)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            j++;
        }
        // col up
        i = king[0] - 1;
        j = king[1];
        while (i >= 0)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            i--;
        }
        //col down
        i = king[0] + 1;
        while (i < 8)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            i++;
        }
        // northwest
        i = king[0] - 1;
        j = king[1] - 1;
        while (i >= 0 && j >= 0)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            i--;
            j--;
        }
        // northeast
        i = king[0] - 1;
        j = king[1] + 1;
        while (i >= 0 && j < 8)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            i--;
            j++;
        }
        // southwest
        i = king[0] + 1;
        j = king[1] - 1;
        while (i < 8 && j >= 0)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            i++;
            j--;
        }
        //southeast
        i = king[0] + 1;
        j = king[1] + 1;
        while (i < 8 && j < 8)
        {
            if (count(queens.begin(), queens.end(), vector<int>{i, j}) == 1)
            {
                res.push_back(vector<int>{i, j});
                break;
            }
            i++;
            j++;
        }
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        /* 
         * Plan:
         * 1. Create a board and mark the places where there are queens.
         * 2. For each direction a queen can go to:
         *      From the position of the king go into the current direction:
         *          If a queen is reached, add it to the result and continue with the next direction.
         *          If the end of the board is reached, continue with the next direction.
         * 3. Return the result.
         */

        array<bool, 64> board{false};           // Array to hold the board.
        for (int i = 0; i < queens.size(); i++) // Fill the queens in the board.
            board[queens[i][0] + queens[i][1] * 8] = true;
        vector<vector<int>> queensThatCanAttack;                                                                                               // Vector to hold answer.
        for (pair<int, int> modifier : initializer_list<pair<int, int>>{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}) // Iterate over the directions a queen can go to.
        {
            for (int i = king[0], j = king[1]; i >= 0 && i < 8 && j >= 0 && j < 8; i += modifier.first, j += modifier.second) // Go from the King towards the current direction until the end of the board is reached.
            {
                if (board[i + j * 8]) // If a queen is found add it to the result and break.
                {
                    queensThatCanAttack.push_back({i, j});
                    break;
                }
            }
        }
        return queensThatCanAttack; // Return the result.
    }
};