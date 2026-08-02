#include <iostream>
#include <chrono>

#include <filesystem>
#include <string>
#include <cstdlib>

using namespace std;
int main(){

    while(true){
        cout<<"=================================";cout<<endl;
        cout<<"||  1. Assignment_01           ||";cout<<endl;
        cout<<"||  2. Exit                    ||";cout<<endl;
        cout<<"=================================";cout<<endl;
        cout<<endl;
        cout<<endl;





        int ass_no;
        cout<<"choose assignment : ";
        cin>>ass_no;
        cout<<endl;

        if(ass_no==1){
            cout<<endl<<endl;
            cout<<"<<=============================================>>";cout<<endl;
            cout<<"=================================================";cout<<endl;
            cout<<"||  1. Matrix Multiplication simple loops      ||";cout<<endl;
            cout<<"||  2. Tilling Method                          ||";cout<<endl;
            cout<<"=================================================";cout<<endl;

            int choice;
            cout<<"Choose Option : ";
            cin>>choice;
            cout<<endl;
            

            switch(choice){

                case 1: {
                        // std::string test = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/tests/test_01.txt";
                        std::string execute = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/assignment_01_exectue_01";

                        std::string drive = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/driver/matrix_multiplication.cpp";
                        std::string src = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/src/matrix_multiplication.cpp";
                        std::string compiler = "g++ "+drive+" "+src+" -o "+execute;
                       

                        std::string test_folder = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/tests";

                        
                        std::cout<<"compiling program....";
                        system(compiler.c_str());

                        // start storing the start time
                        
                        int i=1;
                        for(const auto& entry: std::filesystem::directory_iterator(test_folder)){
                            if(entry.is_regular_file()){

                                
                                std::string run = execute +" < "+ entry.path().string();
                                system(run.c_str()); 
                                i+=1;
                            }
                            
                        }  
                        
                        
                        break;
                }
                case 2:{
                        
                        std::string execute = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/assignment_01_exectue_02";

                        std::string drive = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/driver/tilling_method.cpp";
                        std::string src = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/src/tilling_method.cpp";
                        std::string compiler = "g++ "+drive+" "+src+" -o "+execute;
                       

                        std::string test_folder = "C:/Users/muppu/OneDrive/Desktop/CS509/Individual/assignment_01/tests";

                        
                        std::cout<<"compiling program....";
                        system(compiler.c_str());

                        // start storing the start time
                        
                        int i=1;
                        for(const auto& entry: std::filesystem::directory_iterator(test_folder)){
                            if(entry.is_regular_file()){

                                
                                std::string run = execute +" < "+ entry.path().string();
                                system(run.c_str()); 
                                i+=1;
                            }
                            
                        }  
                        
                        
                        break;
                }
                default:{
                        cout<<"Unknow Operation";
                        break;
                }

            }
        }
        if(ass_no==2){
            cout<<"Exiting from program.";
            cout<<endl;
            break;
        }
}
    return 0;
}