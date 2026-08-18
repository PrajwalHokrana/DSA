class Solution {
private:
    unordered_map<int, string> urlMap;
    int id = 0;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urlMap[id] = longUrl;
        return "http://tinyurl.com/" + to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key = stoi(shortUrl.substr(shortUrl.find_last_of('/') + 1));
        return urlMap[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));