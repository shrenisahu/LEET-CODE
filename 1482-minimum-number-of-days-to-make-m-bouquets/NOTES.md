start = min(start, i);
end = max(end, i);
}
int ans = 0;
​
while (start <= end)
​
{
​
int mid = start + (end - start) / 2;
cout<<mid<<" ,";
​
if (isPossible(bloomDay, m, k, mid))
{
ans = mid;
​
end = mid - 1;
}
else
{
start = mid + 1;
}
}
if(ans==0)
return -1;
return ans;
}
};