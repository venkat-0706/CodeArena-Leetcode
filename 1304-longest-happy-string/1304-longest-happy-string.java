class Solution {
    public String longestDiverseString(int a, int b, int c) {
        Queue<Pair<Integer, Character>> pq = new PriorityQueue<>((e1, e2) -> e2.getKey() - e1.getKey());
        if(a != 0) pq.add(new Pair<>(a, 'a'));
        if(b != 0) pq.add(new Pair<>(b, 'b'));
        if(c != 0) pq.add(new Pair<>(c, 'c'));
        StringBuilder sb = new StringBuilder();

        while(!pq.isEmpty()){
            Pair<Integer, Character> p = pq.remove();
            int val = p.getKey();
            if(val == 1) {
                sb.append(p.getValue());
                val -= 1;
            } else {
                sb.append(p.getValue());
                sb.append(p.getValue());
                val -= 2;
            }

            if(!pq.isEmpty()){
                Pair<Integer, Character> p2 = pq.remove();
                int val2 = p2.getKey();
                sb.append(p2.getValue());
                val2--;

                if(val > 0 && val2 == val){
                    sb.append(p2.getValue());
                    val2--;
                }

                if(val2 != 0) pq.add(new Pair<Integer, Character>(val2, p2.getValue()));
            }
                if(sb.charAt(sb.length() - 1) == p.getValue()) break;
            if(val != 0) pq.add(new Pair<Integer, Character>(val, p.getValue()));
        }
        return sb.toString();
    }
}