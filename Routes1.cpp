// Programmer: Minjoo Kim
// Programmer's ID: 1581736

#include <iostream>
#include <string>
using namespace std;

class Leg{
    const char* const startCity;
    const char* const endCity;
    const double dist;
    
public:
    Leg(const char* const s, const char* const e, double d) : startCity(s), endCity(e), dist(d){}
    double getDist() {return dist;}
    Leg& operator=(const Leg&);
    void niceOutput(ostream&);
};

int main(){
    
    cout << "Programmer: Minjoo Kim\n";
    cout << "Programmer's ID: 1581736\n";
    cout << "File: " << __FILE__ << endl;
    
    Leg ary[] = {
        Leg("Concord","Walnut Creek",6.6),
        Leg("Walnut Creek","Lafayette",4.8),
        Leg("Lafayette","Orinda",5.9),
        Leg("Orinda","Oakland",9.0),
        Leg("Walnut Creek","Alamo",6.3),
        Leg("Alamo","Danville",3.3),
        Leg("Danville","San Ramon",3.2),
        Leg("San Ramon","Pleasanton",11.6),
        Leg("Pleasanton","Hayward",15.7),
        Leg("Hayward","San Leandro",6.9),
        Leg("San Leandro","Oakland",9.6),
        Leg("Oakland","Berkeley",5.4),
        Leg("Berkeley","Richmond",7.6),
        Leg("Richmond","San Quentin",8.8),
        Leg("San Quentin","San Rafael",4.0),
        Leg("San Rafael","Mill Valley",7.6),
        Leg("Mill Valley","San Francisco",14.2),
        Leg("San Francisco","Daly City",9.6),
        Leg("Daly City","Millbrae",10.0),
        Leg("Millbrae","San Mateo",5.9),
        Leg("San Mateo","Belmont",5.0),
        Leg("Belmont","Atherton",8.4),
        Leg("Atherton","Palo Alto",4.2),
        Leg("Palo Alto","Mountain View",7.9),
        Leg("Mountain View","Sunnyvale",2.9),
        Leg("Sunnyvale","Santa Clara",5.1),
        Leg("Santa Clara","San Jose",7.5),
        Leg("San Jose","Milpitas",11.3),
        Leg("Milpitas","Fremont",11.5),
        Leg("Fremont","Union City",8.1),
        Leg("Union City","Hayward",6.5),
        Leg("Hayward","Foster City",14.7),
        Leg("Foster City","San Mateo",4.2),
        Leg("San Jose","Campbell",7.1),
        Leg("Campbell","Los Gatos",4.5),
        Leg("Los Gatos","Scotts Valley",16.6),
        Leg("Scotts Valley","Santa Cruz",6.5),
        Leg("Santa Cruz","Davenport",11.6),
        Leg("Davenport","Swanton",4.8),
        Leg("Swanton","Pescadero",22.0),
        Leg("Pescadero","Lobitos",11.7)
    };
    
    for (int i = 0; i <(sizeof(ary)/sizeof(*ary)); i++){
        for (int j = i + 1; j < (sizeof(ary)/sizeof(*ary)); j++){
            if (ary[j].getDist() < ary[i].getDist()){
                swap(ary[i], ary[j]);
            }
        }
    }
    
    for(auto& i : ary){
        i.niceOutput(cout);
    }
}

Leg& Leg::operator=(const Leg& copyThis){
    Leg& host = *this;
    if(this != &copyThis){
        const_cast<const char*&>(host.startCity) = copyThis.startCity;
        const_cast<const char*&>(host.endCity) = copyThis.endCity;
        const_cast<double&>(host.dist) = copyThis.dist;
    }
    return host;
}

void Leg::niceOutput(ostream& os){
    os << "Leg:" <<startCity << " to " << endCity << ", " << dist << " miles" << endl;
}
