int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 2*n;
        unordered_map<int, char> umap;
        for(auto seat : reservedSeats) {
            //generate bit number
            if(seat[1] > 1 && seat[1] < 10) {
                char tmp = 1 << (seat[1] - 2);
                umap[seat[0]] |= tmp;
            }
        }
        for(auto seat : umap) {
            int p1 = !(seat.second & 0b11110000);
            int p2 = !(seat.second & 0b00111100);
            int p3 = !(seat.second & 0b00001111);
            if(p1 && p3)
                continue;
            else if (p1 || p2 || p3) 
                ans -= 1;
            else 
                ans -= 2;
        }
        return ans;
    }
