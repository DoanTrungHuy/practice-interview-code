class FoodRatings {
public:
    unordered_map<string,int>mp;
    unordered_map<string,string>mp2;
    unordered_map<string,set<pair<int,string>>>hrating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            mp[foods[i]]=ratings[i];
            mp2[foods[i]]=cuisines[i];
            hrating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        string t=mp2[food];
        int tmp=mp[food];
        mp[food]=newRating;
        hrating[t].erase(hrating[t].find({-tmp,food}));
        hrating[t].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        
        string res="";
        auto anss=*(hrating[cuisine].begin());
        res=anss.second;
        return res;
    }
};