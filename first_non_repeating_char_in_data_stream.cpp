// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

class Solution{
	public:
		string FirstNonRepeating(string A){
			// Code here
			list<char>nonRepChar;
			bool seenChar[256];
			list<char>::iterator itOfChar[256];
			string ans;

			for(int i=0;i<256;++i){
				seenChar[i] = 0;
				itOfChar[i] = nonRepChar.end();
			}

			for(auto c:A){ /// consider this as data stream,
				if( seenChar[c] ){
					list<char>::iterator it = itOfChar[c];
					if( it != nonRepChar.end() ){
						nonRepChar.erase(it);
						itOfChar[c] = nonRepChar.end();
					}
				}else{
					nonRepChar.push_back(c);
					seenChar[c] = 1;
					itOfChar[c] = --nonRepChar.end();
				}
				ans.push_back( nonRepChar.empty() ? '#' : nonRepChar.front() );
			}
			return ans;
		}
};
