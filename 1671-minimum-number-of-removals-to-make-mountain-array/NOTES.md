}
// Calculate the decreasing sequence
// The same steps as above but for the decreasing sequence
cont.clear();
cont.push_back(nums[n-1]);
ds[n-1] = 1;
for(int i=n-2; i>=0; i--){
auto it = lower_bound(cont.begin(), cont.end(), nums[i]);
if(it == cont.end()){
cont.push_back(nums[i]);
ds[i] = cont.size()-1;
}else{
*it = nums[i];
ds[i] = distance(cont.begin(), it);
}
}
// Find the longest mountain array
int ans = INT_MAX;
for(int i=1; i<n-1; i++){
if(is[i] && ds[i])
ans = min(ans, n-(is[i]+ds[i]+1));
}
return ans;
}
};