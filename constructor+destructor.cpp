#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel{

    // Encapsulatin says all attributes must be kept as private
    // Their value should only be allowed to change through member function of the class
    // This helps in maintaining menaingful attribute values.
    // Ex: we can apply a condition which doesn't allows to reduce subscriber count below 0
    private:
    string name;
    string ownerName;
    int subscribersCount=0;
    list<string> published_videos;

    public:
    YouTubeChannel() 
    { cout<<"Default constructor is called only if no other cnstructor is specified or the object is initalized without any parameters!\n";}
    YouTubeChannel(string Name, string owner) // Constructor
    {
        name = Name;
        ownerName = owner;
    }
    YouTubeChannel(const YouTubeChannel &channel): 
        name(channel.name), ownerName(channel.ownerName), 
        subscribersCount(channel.subscribersCount), published_videos(channel.published_videos) {}


    void getInfo()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Owner Name: "<<ownerName<<endl;
        cout<<"Subscribers count: "<<subscribersCount<<endl;
        cout<<"Published Viedos:- ";
    
        for(auto video: published_videos)
            cout<<video<<", ";
        cout<<endl<<endl;
    }

    void subscribe()
    {
        subscribersCount++;
    }

    void unsubscribe()
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
    channel1.subscribe();
    channel1.subscribe();
    channel1.publish("OOP in C++");
    channel1.publish("encapsulation");
    channel1.getInfo();

    YouTubeChannel channel2("Errichto", "Errichto");
    for(int i=0;i<1000;i++) channel2.subscribe();
    channel2.publish("Dynamic Programming");

    YouTubeChannel channel3(channel2);
    for(int j=0;j<200;j++) channel3.unsubscribe();
    channel3.publish("Graphs");

    channel2.getInfo();
    channel3.getInfo();

    return 0;

}