//排序算法：冒泡排序、快速排序、归并排序、堆排序、桶排序、插入排序、选择排序、shell排序
 
//交换函数swap
 void swap(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;
}

//冒泡排序
void BublbleSort(vector<int> &nums){
	if(nums.empty())
		return;
	bool flag = true;
	for(int i = 0; flag && i < nums.size()-1; ++i){
		flag = false;
		for(int j = nums.size()-1; j > i; --j){
			if(nums[j-1] > nums[j]){
				swap(nums[j-1], nums[j]);
				flag = true;
			}
		}
	}
}

//快速排序
void QuickSort(vector<int> &nums, int begin, int end){
	if(nums.empty() || begin >= end)
		return;
	int pivot = Partition(nums, begin, end);
	QuickSort(nums, begin, pivot - 1);
	QuickSort(nums, pivot + 1, end);
}
		
int Partition(vector<int> &nums, int begin, int end){
	int mark = nums[begin];
	while(begin < end){
		while(begin < end && nums[end] > mark)
			--end;
		nums[begin] = nums[end];
		while(begin < end && nums[begin] < mark)
			++begin;
		nums[end] = nums[begin];
	}
	nums[begin] = mark;
	return begin;
}

//归并排序
void MergeSort(vector<int> &nums){
	if(nums.empty() || nums.size() == 1)
		return;
	vector<int> temp = nums;
	MSort(nums, 0, nums.size()-1, temp);
}

void MSort(vector<int> &nums, int begin, int end, vector<int> &temp){
	if(begin >= end)
		return;
	int middle = left + (end - begin)/2;
	MSort(nums, begin, middle, temp);
	MSort(nums, middle + 1, end, temp);
	Merge(nums,begin,middle,end,temp);
}
		
void Merge(vector<int> &nums, int begin, int middle, int end, vector<int> &temp){
	int i = begin, j = middle + 1, k = begin;
	while(i <= middle && j <= end){
		if(nums[i] < nums[j]){
			temp[k++] = nums[i++];
		}
		else{
			temp[k++] = nums[j++];
		}
	}
	while(i <= middle){
		temp[k++] = nums[i++];
	}
	while(j <= end){
		temp[k++] = nums[j++];
	}
	for(int l = begin; l <= end; ++l)
		nums[l] = temp[l];
}

//堆排序
void HeapAdjust(vector<int> &nums, int begin, int end) {
	int root_value = nums[begin];

	for (int j = 2 * begin + 1; j <= end; j = j * 2 + 1) {
		if (j < end && nums[j] < nums[j + 1])
			++j;
		if (root_value >= nums[j])
			break;
		nums[begin] = nums[j];
		begin = j;
	}
	nums[begin] = root_value;
}

void HeapSort(vector<int> &nums, int array_length) {
	if (nums.empty() || array_length == 1)
		return;

	for (int i = array_length / 2 - 1; i >= 0; --i)
		HeapAdjust(nums, i, array_length - 1);

	for (int i = array_length - 1; i > 0; --i) {
		swap(nums[0], nums[i]);
		HeapAdjust(nums, 0, i - 1);
	}
}

//桶排序
void BucketSort(vector<int> &nums){
	if(nums.empty() || nums.size() == 1)
		return;
	
	//设置10个桶
	vector<vector<int>> bucket;
	for(int i = 0;i < 10;++i)
		bucket.push_back({});
			
	//将数组中的元素分别置入相应的桶中
	for(int i = 0;i < nums.size();++i){
		bucket[nums[i]/10].push_back(nums[i]);
	}

	//对各个桶中的元素进行排序
	for(int i = 0;i < 10;++i)
		sort(bucket[i].begin(),bucket[i].end());

	//将桶中有序的元素写回数组之中
	int start = 0;
	for(int i = 0;i < 10;++i){
		for(int j = 0;j < bucket[i].size();++j)
			nums[start++] = bucket[i][j];
	}
	
}

//插入排序
void InsertSort(vector<int> &nums){
	if(nums.empty() || nums.size() == 1)
		return;

	int mark, j;
	for(int i = 1;i < nums.size();++i){
		if(nums[i] < nums[i-1]){
			mark = nums[i];
			for(j = i; j > 0 && nums[j] > mark;--j)
				nums[j] = nums[j-1];
			nums[j] = mark;
		}
	}
}

//选择排序
void SelectSort(vector<int> &nums){
	if(nums.empty() || nums.size() == 1)
		return;

	for(int i = 0;i < nums.size()-1;++i){
		int minIndex = i;
		for(int j = i+1;j < nums.size();++j){
			if(nums[j] < nums[minIndex])
				minIndex = j;
		}
		if(minIndex != i)
			swap(nums[i],nums[minIndex]);
	}
}

//shell排序
void ShellSort(vector<int> &nums){
	if(nums.empty() || nums.size() == 1)
		return;

	int j;
	for(int step = nums.size()/2;step > 0;setp /= 2){
		for(int i = step;i < nums.size();++i){
			int temp = nums[i];
			for(j = i; j >= step && nums[j-step] > temp;j -= step){
				nums[j] = nums[j-step];
			}
			nums[j] = temp;
		}
	}
}