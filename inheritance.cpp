#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel{

    // Encapsulatin says all attributes must be kept as private
    // Their value should only be allowed to change through member function of the class
    // This helps in maintaining menaingful attribute values.
    // Ex: we can apply a condition which doesn't allows to reduce subscriber count below 0
    private:  // private data members cannot be accesed in derived classes of this class
    string name;
    int subscribersCount=0;
    list<string> published_videos;

    protected:  // can be accessed in derived classes but not outside of that
    string ownerName;

    public:
    YouTubeChannel() 
    { cout<<"Default constructor is called only if no other cnstructor is specified or the object is initalized without any parameters!\n";}
    YouTubeChannel(string Name, string owner){ // Constructor
        name = Name;
        ownerName = owner;
    }
    YouTubeChannel(const YouTubeChannel &channel): 
        name(channel.name), ownerName(channel.ownerName), 
        subscribersCount(channel.subscribersCount), published_videos(channel.published_videos) {}
    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Owner Name: "<<ownerName<<endl;
        cout<<"Subscribers count: "<<subscribersCount<<endl;
        cout<<"Published Viedos:- ";
    
        for(auto video: published_videos)
            cout<<video<<", ";
        cout<<endl<<endl;
    }
    void subscribe(){
        subscribersCount++;
    }
    void unsubscribe(){
        if(subscribersCount>0)
            subscribersCount--;
    }
    void publish(string video){
        published_videos.push_back(video);
    }
};

class CookingYoutubeChannel: public YouTubeChannel{
    public:
    CookingYoutubeChannel(string Name, string OwnerName): YouTubeChannel(Name,OwnerName) {}
    void practice(){
        cout<<ownerName<<" is practicing new recipies, learning about more spices, having fun!"<<endl;
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
    //channel1.practice().  ** function of sub class not available for super clas


    CookingYoutubeChannel rannaGhor("Ranna Ghor","Susmita");
    rannaGhor.subscribe();
    rannaGhor.subscribe();
    rannaGhor.unsubscribe();
    rannaGhor.subscribe();
    rannaGhor.subscribe();

    rannaGhor.publish("Mangsho Biriyani");
    rannaGhor.publish("Mach Bhaja");
    rannaGhor.getInfo();

    CookingYoutubeChannel niramishBhojon("Niramish Bhojon","Sankar");
    niramishBhojon.subscribe();
    niramishBhojon.subscribe();

    niramishBhojon.publish("Poneer Curry");
    niramishBhojon.getInfo();

    rannaGhor.practice();
    niramishBhojon.practice();


    return 0;

}