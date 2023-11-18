import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Program048 {
    public int[][] merge(int[][] intervals) {
     //leetcode 56
        if(intervals.length <= 1)
        {
            return intervals;
        }
        Arrays.sort(intervals, (arr1, arr2) -> Integer.compare(arr1[0], arr2[0]));//sort by start time
        List<int[]> output = new ArrayList<>();
        int[] currentInterval = intervals[0];
        output.add(currentInterval);
        for(int[] interval : intervals)
        {
            int currentEnd = currentInterval[1];
            int nextBegin = interval[0];
            int nextEnd = interval[1];
            if(currentEnd >= nextBegin)
            {
                currentInterval[1] = Math.max(currentEnd, nextEnd);
            }
            else
            {
                currentInterval = interval;
                output.add(currentInterval);
            }
        }
        return output.toArray(new int[output.size()][]);   
    }
}
