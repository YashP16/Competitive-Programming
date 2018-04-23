int search(int *a, int f, int l, int n){
	while(f<=l)
	{
		int mid=(f+l)/2;
		if(a[mid]<n)
			f=mid+1;
		else if(a[mid]>n)
			l=mid-1;
		else
			return mid;
	}
	return -1;
}

int searchLessThanEqual(int *a, int f, int l, int n){
	int mid;
	while(f<=l)
	{
		mid=(f+l)/2;
		if(a[mid]<n)
			f=mid+1;
		else if(a[mid]>n)
			l=mid-1;
		else
			return mid;
	}
	if(a[mid]>n) mid--;
	return mid;		//use caution of under index
}

int searchGreaterThanEqual(int *a, int f, int l, int n){
	int mid;
	while(f<=l)
	{
		mid=(f+l)/2;
		if(a[mid]<n)
			f=mid+1;
		else if(a[mid]>n)
			l=mid-1;
		else
			return mid;
	}
	if(a[mid]<n) mid++;
	return mid;			///use caution of over index
}

int searchFirst(int *a, int n, int l,int h)
{
	int startIndex = -1;
    while (l <= h) 
    {
        int mid = (h - l) / 2 + l;
        if (a[mid] >=n) 
        {
            h = mid - 1;
        	if (a[mid] == n) 
            	startIndex = mid;
        }
        else
            l = mid + 1;
    }
	return startIndex;    
}

int searchCount(vi &numbers, int target)
{
	int low = 0, high = numbers.sz - 1;

	int startIndex = -1;
    while (low <= high) 
    {
        int mid = (high - low) / 2 + low;
        if (numbers[mid] > target) 
        {
            high = mid - 1;
        }
        else if (numbers[mid] == target) 
        {
            startIndex = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    int endIndex = -1;
    low = 0;
    high = numbers.sz - 1;
    while (low <= high) 
    {
        int mid = (high - low) / 2 + low;
        if (numbers[mid] > target) 
        {
            high = mid - 1;
        }
        else if (numbers[mid] == target) 
        {
            endIndex = mid;
            low = mid + 1;
        }
        else
            low = mid + 1;
    }

    if(endIndex!=-1 && startIndex!=-1)
    	return endIndex-startIndex+1;
    else return 0;
}