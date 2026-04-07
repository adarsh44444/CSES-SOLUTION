class Robot {
public:
    long long width,height;
    vector<pair<long long,long long>> directions={{0,1},{1,0},{0,-1},{-1,0}};
    long long dir_index=1;
    long long x=0,y=0;
    Robot(long long width, long long height) {
        this->width=width;
        this->height=height;
    }
void step(long long num) {
    long long perimeter = 2 * (width + height - 2);
    num %= perimeter;

    if(num == 0){
        if(x == 0 && y == 0){
            dir_index = 2; // West
        }
        return;
    }

    while(num > 0){
        long long nx = x + directions[dir_index].first;
        long long ny = y + directions[dir_index].second;

        if(nx >= 0 && nx < width && ny >= 0 && ny < height){
            x = nx;
            y = ny;
            num--;
        } else {
            dir_index = (dir_index + 3) % 4;  // ✔️ clockwise
        }
    }
} 
    vector<long long> getPos() {
        return {x,y};
    }
    
    string getDir() {
        vector<string> direct={"North","East","South","West"};
        return direct[dir_index];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<long long> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */