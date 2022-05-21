#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel{

    // Encapsulatin says all attributes must be kept as private
    // Their value should only be allowed to change through member function of the class
    // This helps in maintaining menaingful attribute values.
    // Ex: we can apply a condition which doesn't allows to reduce subscriber count below 0
    private:
    string Name;
    string ownerName;
    int subscribersCount=0;
    list<string> published_videos;

    public:
    YouTubeChannel() 
    { cout<<"Default constructor is called only if no other cnstructor is specified or the object is initalized without any parameters!\n";}
    YouTubeChannel(string name, string owner) // Constructor
    {
        Name = name;
        ownerName = owner;
    }


    void GetInfo()
    {
        cout<<"Name: "<<Name<<endl;
        cout<<"Owner Name: "<<ownerName<<endl;
        cout<<"Subscribers count: "<<subscribersCount<<endl;
        cout<<"Published Viedos:- "<<endl;
    
        for(auto video: published_videos)
            cout<<video<<endl;
        cout<<endl;
    }

    void Subscribe()
    {
        subscribersCount++;
    }

    void Unsubscribe()
    {
        if(subscribersCount>0)
            subscribersCount--;
    }

    void publish(string video)
    {
        published_videos.push_back(video);
    }



};

int main()
{
    YouTubeChannel channel1("CodeBeauty","Southena");
    channel1.Subscribe();
    channel1.Subscribe();
    channel1.publish("OOP in C++");
    channel1.publish("encapsulation");
    channel1.GetInfo();

    return 0;

}