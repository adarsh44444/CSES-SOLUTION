class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> rcpidx;
        unordered_set<string> available(supplies.begin(), supplies.end());
        vector<int> indegree(recipes.size(), 0);
        unordered_map<string, vector<string>> dependency;

        for (int i = 0; i < recipes.size(); i++) {
            rcpidx[recipes[i]] = i;
        }

        for (int i = 0; i < recipes.size(); i++) {
            for (const auto& it : ingredients[i]) {
                if (available.find(it) == available.end()) {
                    dependency[it].push_back(recipes[i]);
                    indegree[i]++;
                }
            }
        }

        queue<pair<string, int>> q;
        for (int i = 0; i < recipes.size(); i++) {
            if (indegree[i] == 0) {
                q.push({recipes[i], i});
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            string res = q.front().first;
            int idx = q.front().second;
            q.pop();

            ans.push_back(res);
            available.insert(res);

            for (const auto& dependentRecipe : dependency[res]) {
                int depIdx = rcpidx[dependentRecipe];
                indegree[depIdx]--;
                if (indegree[depIdx] == 0) {
                    q.push({dependentRecipe, depIdx});
                }
            }
        }

        return ans;
    }
};
