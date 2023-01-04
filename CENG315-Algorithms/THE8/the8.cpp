#include "the8.h"

//DO NOT ADD OTHER LIBRARIES


void matchPattern(const std::string& sequence, const std::pair<std::string,std::string> mapping, const std::string& pattern){


    /*****************
     *
     * 
     * YOU SHOULD PRINT THE STARTING INDEX OF EACH MATCH 
     * IN THE SAME LINE, SEPARATED BY A SINGLE SPACE
     * 
     * IF THERE IS NO MATCH, YOU SHOULD PRINT "NONE"
     *
     * *************/
    int s_length=sequence.length();
    int p_length=pattern.length();
    
    int *table=new int[p_length+1];
    
    int k=1;
    int temp=0;
    table[0]=0;
    std::vector <int> indices;
    
    //std::cout<<(mapping.first=="T");
    while(k<=p_length){
        if(temp==0){
            if(pattern[temp]==pattern[k]){
                temp++;
                table[k]=temp;
                k++;
            }
            
            else{
                table[k]=0;
                k++;
            }
        }
        
        else{
            if(pattern[temp]==pattern[k]){
                temp++;
                table[k]=temp;
                k++;
            }
            
            else{
                temp=table[temp-1];
                k++;
            }
        }
        
    }
    
    /*for(int i=0;i<p_length+1;i++){
        std::cout<<table[i]<<" ";
    }*/
    
    temp=0;
    k=0;
    bool found=false;
    while(k<=s_length){
        
        if(temp==0){
            //std::cout<<"temp is 0 checking "<<sequence[k]<<" vs "<<pattern[temp]<<std::endl;
            if (sequence[k]==pattern[temp]||(sequence[k]==mapping.first[0]&&mapping.second[0]==pattern[temp])||(sequence[k]==mapping.second[0]&&mapping.first[0]==pattern[temp])){
                temp++;
                k++;
                //std::cout<<"match found incrementing k to:"<<k<<" incrementing temp to:"<<temp<<std::endl;
            }
            else{
                k++;
                //std::cout<<"no match incrementing k to:"<<k<<std::endl;
            }
        }
        
        
        else{
            if(sequence[k]==pattern[temp]||(sequence[k]==mapping.first[0]&&mapping.second[0]==pattern[temp])||(sequence[k]==mapping.second[0]&&mapping.first[0]==pattern[temp])){
                temp++;
                k++;
                //std::cout<<"match found incrementing k to:"<<k<<" incrementing temp to:"<<temp<<std::endl;
            }
            else{
                temp=table[temp-1];
                //std::cout<<"no match changing temp to:"<<temp<<std::endl;
            }
            
            if(temp==p_length){
                indices.push_back(k-temp);
                found=true;
                //std::cout<<"temp max full pattern found at:"<<k-temp<<std::endl;
                temp=table[temp-1];
                //std::cout<<"changing temp to:"<<temp<<std::endl;
            }
            
            
        }
        
        
    }
    
    
    
    if(found){
        bool first_print=true;
        for(auto i:indices){
            if(first_print){
                std::cout<<i;
                first_print=false;
            }
            else{
                std::cout<<' '<<i;
            }
        }
    }
    else{
        std::cout<<"NONE";
    }
     
}
