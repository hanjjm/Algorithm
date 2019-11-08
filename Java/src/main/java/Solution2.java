import java.util.ArrayList;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution2 {
	public int[] solution(int[] arr, int divisor) {
		int[] answer = {};
		ArrayList<Integer> arrayList = new ArrayList<>();
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] % divisor == 0) arrayList.add(arr[i]);
		}

		if(arrayList.size() != 0) {
			answer = new int[arrayList.size()];
			for(int i = 0; i < arrayList.size(); i++)
				answer[i] = arrayList.get(i);
			Arrays.sort(answer);
		}
		else {
			answer = new int[1];
			answer[0] = -1;
		}

		return answer;
	}
}
