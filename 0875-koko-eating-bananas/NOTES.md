​
int start = 1;
int end = maxElem;
int ans = 0;
while(start<=end)
{
int mid=start+end/2;
if(isPossible(piles,h,mid))
{
ans=mid;
end=mid-1;
}
else
{
start=mid+1;
}
}
return ans;
}
};