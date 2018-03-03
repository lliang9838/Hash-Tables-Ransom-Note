// my own code for ransom_note
// I learned about iterators, map and unordered maps..
// learned about find()
// learned how to iterate the stl using iterators

bool ransom_note(vector<string> magazine, vector<string> ransom)
{

    //build two hash tables

    int m_length = magazine.size();
    int r_length = ransom.size();

    unordered_map<string, int> mag_map;
    unordered_map<string, int> ran_map;

    for ( int i =0; i < m_length; i++)
    {
        string tmp = magazine[i];
        unordered_map<string, int>::iterator got = mag_map.find(tmp);
        //can use got, or can simply do mag_map.find(tmp) since that automatically returns an iterator position
        if ( got!=mag_map.end())
        {
            //then this means that tmp already exists in mag_map
            mag_map.at(tmp) += 1;
        }
        else
        {
            mag_map.insert( {tmp, 1} );
        }
    }

     for ( int i =0; i < r_length; i++)
    {
        string tmp = ransom[i];
        unordered_map<string, int>::iterator got = ran_map.find(tmp);
        if ( got!=ran_map.end())
        {
            //then this means that tmp exists in mag_map
            ran_map.at(tmp) += 1;
        }
        else
        {
            ran_map.insert( {tmp, 1} );
        }
    }


    unordered_map<string, int>::iterator it = ran_map.begin();
    while ( it!=ran_map.end())
    {
        string tmp = it->first; //equivalent to *(it).first
        unordered_map<string, int>::iterator got = mag_map.find(tmp);
        if ( got!=mag_map.end())
        {
            //that means tmp is found in mag_map
            if ( it->second > got->second ) //changed = to >, this should give me full score lol
            {
              //why != didn't give me a fullscore, how come > did
              // this is because if the magazine has more occurrences, that's okay.
              //But we cannot have the ransom note having more occurrences....
              // we would only return false if ransom note had more occurences than magazine,
              // we should not return false when their occurences are not equal, instead, we
              //would not be able to create the ransom note if the # of occur. in the ransom
              //note is > than # of occur. in magazine.
              //we can still create the magazine has more occur. than ransom note.

                return false; //if the times that they occur is false

                // we would only return false here if the # of occurrences in
                // the ransom note is greater than the # of occurrences in
                // the magazine..

                // before, I would return false just when the # of occurrents of each
                //not equal, this is simply false since I'll still be able to create a
                //legit ransom note when I have more occurrences in maganzine than ransom note
                //, this is not true bc if got->second is > than it->second,
                //we can still get a legit ransom note even though the number of
                //occurences in got->second!=it->second.


            }

        }
        else
        {
            //something in ransom is not found in mag
            return false;
        }


        it++;
    }


    return true;

}

// EDITIORIAL SOLUTION
#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    int n;
    cin >> m >> n;

    map<string, int> magazine;
    map<string, int> note;

    string word;

    for(int i = 0; i < m; i++) {
        cin >> word;
        magazine[word]++;
        //If you call it with a key that's not yet in the map,
        //it will default-construct a new instance of Value,
        //put it in the map under key you passed in, and return a reference to it.
    }

    for(int i = 0; i < n; i++) {
        cin >> word;
        note[word]++;
        //In the end, your code puts a new pair (wstrPlayerName, 0)
        //in the map, then returns a reference to the int, which
        //you then increment. So, there's no need to test if the
        //element exists yet if you want things to start from 0.
    }

    map<string, int> :: iterator it;
    bool success = 1;

    for(it = note.begin(); it != note.end(); it++) {
        if(magazine[it->first] < it->second) {
//if it doesn't occur in magazine, magazine[it->first] gives us 0
//(default constructured to 0), and 1 would be greater than 0 and
//we would change the success flag to 0.
            success = 0;
            break;
        }
    }

    if(success) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}
// https://stackoverflow.com/questions/507971/do-stl-maps-initialize-primitive-types-on-insert
