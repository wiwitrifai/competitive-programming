#include <bits/stdc++.h>

using namespace std;

set<string> can = {"access","ache","act","address","aim","alert","answer","arrest","attack","auction","back","bail","balance","balloon","ban","bandage","bank","bare","bargain","battle","beam","bear","beat","bend","benefit","blame","blast","bleach","block","bloom","blow","board","bomb","bother","bounce","bow","box","bread","break","breed","broadcast","brush","bump","burn","buy","cake","call","camp","care","catch","cause","challenge","change","chant","charge","cheat","check","cheer","chip","claim","clip","cloud","clue","coach","color","comb","comfort","contrast","control","cook","coop","copy","cost","count","cover","crack","crash","crate","credit","crush","cure","curl","curve","cut","cycle","dam","damage","dance","deal","decay","decrease","delay","delight","demand","design","dial","die","dislike","display","dive","divorce","dock","double","doubt","drain","draw","dream","dress","drill","drink","drive","duck","dump","dust","dye","echo","email","end","escape","esteem","estimate","exchange","excuse","exhibit","experience","eye","face","fall","favor","fax","fear","feel","fight","file","fill","film","finish","fish","fix","flap","flash","float","flood","floss","flow","flower","fly","fold","fool","force","form","frame","freeze","frown","function","garden","gaze","gel","glue","grate","grease","grill","grimace","grin","grip","guarantee","guard","guess","guide","hammer","hand","handle","harm","harness","hate","head","heap","heat","help","hide","highlight","hike","hit","hold","hop","hope","hose","hug","humor","hunt","hurry","ice","impact","inch","increase","influence","insult","interest","iron","itch","jail","jam","joke","judge","jump","keep","kick","kiss","knit","knock","knot","label","land","last","laugh","lead","leap","level","license","lie","lift","light","limit","link","load","loan","lock","look","love","mail","make","man","march","mark","match","mate","matter","mean","measure","milk","mind","mine","miss","mistake","moor","move","mug","nail","name","need","nest","notch","note","notice","number","object","offer","oil","order","pack","pad","paddle","paint","park","part","pass","paste","pause","pat","pay","pedal","peel","pelt","permit","phone","photograph","pick","pine","place","plan","plane","plant","play","plow","plug","point","poke","pop","post","practice","praise","present","process","produce","promise","protest","pull","pump","punch","push","question","quilt","quiz","race","rain","raise","rant","rate","reach","reason","record","reign","rent","repair","reply","report","request","rhyme","ring","riot","risk","rock","roll","row","ruin","rule","run","sail","sand","saw","scare","scratch","screw","search","season","sense","shampoo","shape","share","shelter","shock","shop","show","sign","signal","silence","sin","sip","skate","sketch","ski","slice","slide","slip","smell","smile","smirk","smoke","snack","snow","sound","span","spot","spray","sprout","squash","stain","stamp","stand","star","start","state","steer","step","sting","stop","store","storm","stress","strip","stroke","struggle","study","stuff","stunt","suit","supply","support","surf","surprise","swap","swing","swivel","tack","talk","taste","tear","tease","telephone","test","thunder","thought","tick","tie","time","tip","tire","toast","touch","tour","tow","trace","track","trade","train","transport","trap","travel","treat","trick","trim","trust","tug","turn","twist","type","upstage","use","vacuum","value","visit","voice","vote","walk","waltz","wake","watch","water","wave","wear","whip","whisper","whistle","wick","wink","wire","wish","work","worry","wrap","wreck","yawn","yield","zone"};
set<string> cannot = {"food", "office", "universe", "noodle", "volume", "aeroplane"};

int main() {
  srand(time(0));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (can.count(s))
      puts("can");
    else
      puts("cannot");
  }
  return 0;
}