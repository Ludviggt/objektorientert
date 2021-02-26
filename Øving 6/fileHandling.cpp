#include "fileHandling.h"
#include "std_lib_facilities.h"

void skrivInnOrd(){
    
    cout << "Skriv inn navnet paa outputfilen: ";
    string oFileName;
    cin >> oFileName;
    ofstream myFile{oFileName};
    if(!myFile){
    error("Cannot open file");//sjekker at filen ble åpnet riktig
    }
    string ord;
    while(ord != "quit"){
        cout << "Skriv inn ord til fil, avslutt med quit: ";
        cin >> ord;
        if ( ord !="quit"){
        myFile << ord <<'\n';
        }
    }
}

void readFromFileWriteToFile(){
    cout <<"Type the name of the inputfile: ";
    string iName;
    cin >> iName;
    ifstream inputFile{iName};
    if(!inputFile){
    error("Cannot open file");//sjekker at filen ble åpnet
    }
    
    string streng{};
    vector<string> lestInput;
    while(getline(inputFile, streng)){
       
        lestInput.push_back(streng); // Lagrer fillinjene i en vektor
    }
    inputFile.close();
    cout <<"\nType the name of the outputfile: ";
    string oName;
    cin >> oName;
    ofstream outputFile{oName};
    if(!outputFile){
    error("Cannot open file");//sjekker at filen ble åpnet
    }
    for( int i=0; i<streng.size(); ++i){
        outputFile <<(i+1) << " "  << lestInput[i] << endl;
    }
    outputFile.close();

}


void countInstancesAndFreq(){
    map<char,int> telleChars{
        {'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0}
        ,{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},{'y',0},{'z',0},
        };
    cout <<"Type the name of the inputfile: ";
    string iName;
    cin >> iName;
    ifstream inputFile{iName};
    char bokstav;
    if(!inputFile){
        error("Cannot open file");//sjekker at filen ble åpnet
    }
    while(inputFile >> bokstav){
        if( tolower(bokstav)>='a' && tolower(bokstav)<='z'){
            telleChars[tolower(bokstav)]++;
        }
    }
    for (const auto& c: telleChars){
        cout << c.first << " " << c.second<<endl; 
    }
    
}


void CourseCatalog::addCourse(string emneKode, string emneNavn){
    emneKodeToEmneNavn.insert({emneKode,emneNavn});

}

void CourseCatalog::removeCourse(string emneKode){
    emneKodeToEmneNavn.erase(emneKode);

}
string CourseCatalog::getCourse(string emneKode){
    return emneKodeToEmneNavn[emneKode];
}

ostream& operator<<(ostream& os, const CourseCatalog& cc){
    for(const auto& c : cc.emneKodeToEmneNavn)
        os << c.first << ", " << c.second <<endl;
    return os;
}

void testEmneKatalog(string inputfileName, string outputfilename) {
	CourseCatalog cc;

	cout << "\nFormatet paa utskriften av katalogen:\n";
	cc.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	cc.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	cc.addCourse("TMA4100", "Matematikk 1");
	cout << cc << endl;
    cc.removeCourse("TDT4102");
    cc.addCourse("TDT4102","C++");
    cout << cc;

    cc.saveData(inputfileName);
    cc.writeToFile(outputfilename);

}

void CourseCatalog::saveData(const string& fileName){
    ifstream inputFile{fileName};
    string streng;
    string emneKode, emneNavn;
    emneKodeToEmneNavn.clear();
    if(!inputFile){
        error("Cannot open file");//sjekker at filen ble åpnet
    }
    while(getline(inputFile, streng)){
        for(const auto& c:streng){
            while(c!=','){
                emneKode.push_back(c);
            }
            emneNavn.push_back(c);
            addCourse(emneKode,emneNavn);
        }
    }
    inputFile.close();
}

void CourseCatalog::writeToFile(const string& fileName){
    
    ofstream outputFile{fileName};
    if(!outputFile){
    error("Cannot open file");//sjekker at filen ble åpnet
    }
    for (const auto& c : emneKodeToEmneNavn){
		outputFile << c.first << ", " << c.second << '\n';
    }
    outputFile.close();
 }