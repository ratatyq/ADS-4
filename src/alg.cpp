// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int left_count = 1;
      int right_count = 1;
      while (left + 1 < right && arr[left] == arr[left + 1]) {
        left_count++;
        left++;
      }
      while (right - 1 > left && arr[right] == arr[right - 1]) {
        right_count++;
        right--;
      }
      count += left_count * right_count;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    int index = binarySearch(arr, i + 1, len - 1, target);
    if (index != -1) {
      count++;
      int j = index + 1;
      while (j < len && arr[j] == target) {
        count++;
        j++;
      }
      j = index - 1;
      while (j > i && arr[j] == target) {
        count++;
        j--;
      }
    }
    while (i + 1 < len - 1 && arr[i] == arr[i + 1]) {
      i++;
    }
  }
  return count;
}
