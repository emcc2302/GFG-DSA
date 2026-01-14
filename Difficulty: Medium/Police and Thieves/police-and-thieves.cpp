class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        // Queues to store indexes of police and thieves
        queue<int> police, thief;
        
        // Fill the queues with respective indices
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police.push(i);
            else
                thief.push(i);
        }
        
        int result = 0;
        
        // Match thieves and police
        while (!police.empty() && !thief.empty()) {
            int pIndex = police.front();
            int tIndex = thief.front();
            
            // If they are within k distance, match and pop both
            if (abs(pIndex - tIndex) <= k) {
                result++;
                police.pop();
                thief.pop();
            }
            // If policeman is too left, pop police
            else if (pIndex < tIndex)
                police.pop();
            // If thief is too left, pop thief
            else
                thief.pop();
        }
        
        return result;
    }
};
