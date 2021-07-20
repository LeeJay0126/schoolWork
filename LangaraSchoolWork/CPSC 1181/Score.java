       public class Score
       {
          Private String name;
          Public String getName(){return name;}
          public boolean equals(Object otherScore)  
          {
             Score other = (Score) otherscore;
             return name.equals(other.getName());
          }
       }