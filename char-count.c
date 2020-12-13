#include <stdio.h>

int main(){
    char character;
    int word_count=0, sentence_count=0, character_count=0;
    char spy_char;

    while(1){
        scanf("%c",&character);
        
        if(character=='\n'){
            break;
        } else if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
            spy_char = character;
            character_count++;
        }
        else if(character == ' '){
            if(spy_char == character){
                continue;
            }
            spy_char = character;
            word_count++;
            
        }
        
        
    }
     
    printf("character: %d\n",character_count);
    printf("word: %d\n", ++word_count);
    
    return 0;
}