class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:

        order = sorted(range(len(times)), key = lambda x: times[x][0]) 
        emptySeats, takenSeats = list(range(len(times))), []           

        for i in order:                                               
            ar, lv = times[i]

            while takenSeats and takenSeats[0][0] <= ar:
                heappush(emptySeats, heappop(takenSeats)[1])
            seat = heappop(emptySeats)                                  

            if i == targetFriend: return seat

            heappush(takenSeats,(lv, seat))                         