// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int pairs = 0;
  for (int first = 0; first < len; first++) {
    for (int second = first + 1; second < len; second++) {
      if (arr[first] + arr[second] == value) {
        pairs++;
      }
    }
  }
  return pairs;
}

int countPairs2(int* arr, int len, int value) {
  int result = 0;
  int right = len - 1;
  while (right >= 0 && arr[right] > value) {
    right--;
  }
  for (int left = 0; left < right; left++) {
    int current = arr[left];
    for (int j = right; j > left; j--) {
      if (current + arr[j] == value) {
        result++;
      }
    }
  }
  return result;
}

int findMatches(int* array, int start, int end, int target) {
  int matches = 0;
  while (start <= end) {
    int middle = start + (end - start) / 2;
    if (array[middle] == target) {
      matches++;
      for (int i = middle - 1; i >= start && array[i] == target; i--) {
        matches++;
      }
      for (int i = middle + 1; i <= end && array[i] == target; i++) {
        matches++;
      }
      return matches;
    } else if (array[middle] < target) {
      start = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return matches;
}

int countPairs3(int* arr, int len, int value) {
  int total = 0;
  for (int i = 0; i < len - 1; i++) {
    int needed = value - arr[i];
    total += findMatches(arr, i + 1, len - 1, needed);
  }
  return total;
}
