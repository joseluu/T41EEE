
#include "SDT.h"

uint8_t FIR_filter_window = 1;


float32_t HP_DC_Filter_Coeffs2[5] = {
  // High pass 4.79KHz Butterworth 1 pole // AFP 11-04-22
  0.927176191943378969,
  -0.927176191943378969,
  0.000000000000000000,
  0.854352383886757938,
  0.000000000000000000,
};

float32_t HP_DC_Filter_Coeffs[15] = {  //2KHz
  0.939110434187240273, -1.878220868374480550, 0.939110434187240273, 1.876175647911858760, -0.880266088837102556,
  0.954420583383374654, -1.908841166766749310, 0.954420583383374654, 1.906762603441262800, -0.910919730092235702,
  0.982153973603849595, -1.964307947207699190, 0.982153973603849595, 1.962168985344285850, -0.966446909071112525
};

// ============ AFP 10-25-22 end

//=== CW Filter ===
// == CW FIR 64 taps 24ksps Fc = 1560 Parks-McCellan Sinc window (Constant group delay)
FLASHMEM float32_t CW_Filter_Coeffs2[64] = {
  14.11649337493100380E-6,
  26.00645116880263790E-6,
  36.68870031589199950E-6,
  13.68412619593411960E-6,
  -78.97178111806820770E-6,
  -270.5543007271240870E-6,
  -560.2226272240251320E-6,
  -895.0536349136069700E-6,
  -0.001157191426061149,
  -0.001175458847337361,
  -766.0401423335821390E-6,
  198.2564157371532760E-6,
  0.001706652959686771,
  0.003541671954793736,
  0.005255696919539346,
  0.006219189024066382,
  0.005752477145569307,
  0.003326972676367999,
  -0.001205019703557342,
  -0.007414366866133686,
  -0.014201761944376253,
  -0.019862184667500584,
  -0.022329078747153890,
  -0.019572975891131203,
  -0.010081421213164831,
  0.006688661092777364,
  0.030004344392895913,
  0.057792920156185819,
  0.086867005627322011,
  0.113416964025259234,
  0.133680156710101528,
  0.144647031609622528,
  0.144647031609622528,
  0.133680156710101528,
  0.113416964025259234,
  0.086867005627322011,
  0.057792920156185819,
  0.030004344392895913,
  0.006688661092777364,
  -0.010081421213164831,
  -0.019572975891131203,
  -0.022329078747153890,
  -0.019862184667500584,
  -0.014201761944376253,
  -0.007414366866133686,
  -0.001205019703557342,
  0.003326972676367999,
  0.005752477145569307,
  0.006219189024066382,
  0.005255696919539346,
  0.003541671954793736,
  0.001706652959686771,
  198.2564157371532760E-6,
  -766.0401423335821390E-6,
  -0.001175458847337361,
  -0.001157191426061149,
  -895.0536349136069700E-6,
  -560.2226272240251320E-6,
  -270.5543007271240870E-6,
  -78.97178111806820770E-6,
  13.68412619593411960E-6,
  36.68870031589199950E-6,
  26.00645116880263790E-6,
  14.11649337493100380E-6
};

// ============ AFP 09-23-22 end
//AFP updated entire file 01-16-22
//=== CW Filter ===
//--------------------------  CW Filter IIR coefficients fc= 720, BW= 480 Butterworth  -------------------
float32_t CW_Filter_Coeffs[40] = {
  -0.052435730923943512, 0.000000000000000000, 0.052435730923943512, 1.873536650623021550, -0.903491018266337598,
  -0.051776963065707407, 0.000000000000000000, 0.051776963065707407, 1.854421028977223380, -0.892140154407832897,
  -0.053279899528479190, 0.000000000000000000, 0.053279899528479190, 1.901909218086668130, -0.926406121830538831,
  -0.051720218776406826, 0.000000000000000000, 0.051720218776406826, 1.852473692114126940, -0.899287118048469503,
  -0.054005568085281293, 0.000000000000000000, 0.054005568085281293, 1.933191203570882030, -0.954501171264401371,
  -0.052478365750058854, 0.000000000000000000, 0.052478365750058854, 1.872162227117124540, -0.927509206002122499,
  -0.054571370864953707, 0.000000000000000000, 0.054571370864953707, 1.964566474379490390, -0.984561106211203962,
  -0.053941343239090896, 0.000000000000000000, 0.053941343239090896, 1.911926697739624980, -0.973194327505971346
};
//=== end CW Filter ===

//=================== Excite Coefficients ============
//48 Tap Kaiser 192KHz 8HKZ Fc filters Dec and Interpolation

float32_t coeffs192K_10K_LPF_FIR[48] = {
  -9.489855110236549150E-6,
  162.0562443716462440E-6,
  336.4923361276530040E-6,
  670.1825668306562420E-6,
  0.001118525968862066,
  0.001579147826767285,
  0.001852971855408917,
  0.001654834862116168,
  672.0062171704363440E-6,
  -0.001330388414656256,
  -0.004370672204695505,
  -0.008116214105266742,
  -0.011801558382590140,
  -0.014244430060197440,
  -0.013991286573630231,
  -0.009591314629104829,
  55.15979573749079630E-6,
  0.015330868054737832,
  0.035648433279783398,
  0.059353733010970522,
  0.083890755684744231,
  0.106176326681328731,
  0.123138113118064343,
  0.132306356993624447,
  0.132306356993624447,
  0.123138113118064343,
  0.106176326681328731,
  0.083890755684744231,
  0.059353733010970522,
  0.035648433279783398,
  0.015330868054737832,
  55.15979573749079630E-6,
  -0.009591314629104829,
  -0.013991286573630231,
  -0.014244430060197440,
  -0.011801558382590140,
  -0.008116214105266742,
  -0.004370672204695505,
  -0.001330388414656256,
  672.0062171704363440E-6,
  0.001654834862116168,
  0.001852971855408917,
  0.001579147826767285,
  0.001118525968862066,
  670.1825668306562420E-6,
  336.4923361276530040E-6,
  162.0562443716462440E-6,
  -9.489855110236549150E-6
};
float32_t coeffs48K_8K_LPF_FIR[48] = {
  42.07251256297374200E-6,
  -140.7585461814297220E-6,
  -474.6573692370658360E-6,
  -910.1877217000583190E-6,
  -0.001002380560950271,
  -214.0330069096950180E-6,
  0.001476493526486391,
  0.003032917910844886,
  0.002651184249675911,
  -799.0261189923908200E-6,
  -0.006003327154821903,
  -0.008881895242516839,
  -0.005014510701112499,
  0.006071336723217765,
  0.018084892184059984,
  0.020179984097194015,
  0.004666151232929589,
  -0.024269532666953794,
  -0.047977714295749374,
  -0.041374408930560248,
  0.011283003090050767,
  0.102653022828769605,
  0.201046155814701449,
  0.264813622122047398,
  0.264813622122047398,
  0.201046155814701449,
  0.102653022828769605,
  0.011283003090050767,
  -0.041374408930560248,
  -0.047977714295749374,
  -0.024269532666953794,
  0.004666151232929589,
  0.020179984097194015,
  0.018084892184059984,
  0.006071336723217765,
  -0.005014510701112499,
  -0.008881895242516839,
  -0.006003327154821903,
  -799.0261189923908200E-6,
  0.002651184249675911,
  0.003032917910844886,
  0.001476493526486391,
  -214.0330069096950180E-6,
  -0.001002380560950271,
  -910.1877217000583190E-6,
  -474.6573692370658360E-6,
  -140.7585461814297220E-6,
  42.07251256297374200E-6
};

//4 pole Butterworth IIR biQuad filters for EQ  Band 1 thru 14
float32_t EQ_Band1Coeffs[20] = {  //  fc=198.425 BW=60.4, 4 pole Gaussian 1/3 octave
  -0.010740354324803263, 0.000000000000000000, 0.010740354324803263, 1.977760288071182870, -0.980176703912204905,
  -0.010717730957944621, 0.000000000000000000, 0.010717730957944621, 1.975162619174023470, -0.978112070242933007,
  -0.012264037490550410, 0.000000000000000000, 0.012264037490550410, 1.982731279215446560, -0.984673419072692013,
  -0.012192623012836674, 0.000000000000000000, 0.012192623012836674, 1.975260232124987250, -0.978939586475078283
};
float32_t EQ_Band2Coeffs[20] = {  //  fc=250 BW=72, 4 pole Gaussian 1/3 octave
  -0.012933654120114928, 0.000000000000000000, 0.012933654120114928, 1.972230388754230070, -0.976074773963381825,
  -0.012902245256420676, 0.000000000000000000, 0.012902245256420676, 1.969054007796797960, -0.973704415266133827,
  -0.014776626826402213, 0.000000000000000000, 0.014776626826402213, 1.978267317735213690, -0.981387851708867331,
  -0.014677312538120893, 0.000000000000000000, 0.014677312538120893, 1.969044730844959010, -0.974791905478009535
};
float32_t EQ_Band3Coeffs[20] = {  //  fc=314.98 BW=91.6, 4 pole Gaussian 1/3 octave
  -0.016447315569307643, 0.000000000000000000, 0.016447315569307643, 1.963525244582037700, -0.969599143160199128,
  -0.016395762539476878, 0.000000000000000000, 0.016395762539476878, 1.959197203291359160, -0.966559998362339301,
  -0.018810466262295416, 0.000000000000000000, 0.018810466262295416, 1.971448267819779780, -0.976369169522296243,
  -0.018647471180391263, 0.000000000000000000, 0.018647471180391263, 1.958784738577257430, -0.967908806523534615
};
float32_t EQ_Band4Coeffs[20] = {  //  fc=400 BW=117, 4 pole Gaussian 1/3 octave
  -0.021107226123143540, 0.000000000000000000, 0.021107226123143540, 1.951288180543548690, -0.961023369255779913,
  -0.021020814241623810, 0.000000000000000000, 0.021020814241623810, 1.945259100240296800, -0.957088989767100218,
  -0.024173376764279130, 0.000000000000000000, 0.024173376764279130, 1.961858154037972480, -0.969728310529273663,
  -0.023900201823886549, 0.000000000000000000, 0.023900201823886549, 1.944062548127177160, -0.958769747478319112
};
float32_t EQ_Band5Coeffs[20] = {  //  fc=500 BW=140, 4 pole Gaussian 1/3 octave
  -0.025434986078352932, 0.000000000000000000, 0.025434986078352932, 1.937763026417761440, -0.952954919636953890,
  -0.025313478543573947, 0.000000000000000000, 0.025313478543573947, 1.930070471504943040, -0.948402481405460684,
  -0.029161895846570862, 0.000000000000000000, 0.029161895846570862, 1.950890858299041410, -0.963270463464314108,
  -0.028777241258184545, 0.000000000000000000, 0.028777241258184545, 1.927932418232654040, -0.950564622747441468
};
float32_t EQ_Band6Coeffs[20] = {  //  fc=630 BW=185, 4 pole Gaussian 1/3 octave
  -0.034013087998603600, 0.000000000000000000, 0.034013087998603600, 1.913595532476039860, -0.937338704287993485,
  -0.033779293097819303, 0.000000000000000000, 0.033779293097819303, 1.901882114205436290, -0.930895742996760700,
  -0.039105400046163162, 0.000000000000000000, 0.039105400046163162, 1.932301402855366890, -0.951404949215225448,
  -0.038366657914332684, 0.000000000000000000, 0.038366657914332684, 1.897086382739862300, -0.933431909185264641
};

float32_t EQ_Band7Coeffs[20] = {  //  fc=793 BW=215, 4 pole Gaussian 1/3 octave
  -0.040044359954689926, 0.000000000000000000, 0.040044359954689926, 1.888394203397243400, -0.925981923711014732,
  -0.039740115320392844, 0.000000000000000000, 0.039740115320392844, 1.873614715169800600, -0.918946600083319409,
  -0.046099397613266917, 0.000000000000000000, 0.046099397613266917, 1.911355633900693180, -0.942046227315978979,
  -0.045135819293132796, 0.000000000000000000, 0.045135819293132796, 1.866325392810697090, -0.922355399057854686
};

float32_t EQ_Band8Coeffs[20] = {  //  fc=1000 BW=270, 4 pole Gaussian 1/3 octave
  -0.050982851195012183, 0.000000000000000000, 0.050982851195012183, 1.846967337210932980, -0.905880344373915625,
  -0.050478998559837972, 0.000000000000000000, 0.050478998559837972, 1.825700576400176360, -0.896927722306557262,
  -0.058875166968515282, 0.000000000000000000, 0.058875166968515282, 1.878257463261961750, -0.926279459225752610,
  -0.057280286665948199, 0.000000000000000000, 0.057280286665948199, 1.812808299361427180, -0.901187303394047512
};

float32_t EQ_Band9Coeffs[20] = {  //1259 326 4 pole Gaussian 1/3 octave
  -0.062436305349349887, 0.000000000000000000, 0.062436305349349887, 1.792407090214479080, -0.884627616406695516,
  -0.061695827132588178, 0.000000000000000000, 0.061695827132588178, 1.763182364434806800, -0.874136164738794852,
  -0.072306422223616690, 0.000000000000000000, 0.072306422223616690, 1.833501777433602210, -0.909146391672414067,
  -0.069961857687408896, 0.000000000000000000, 0.069961857687408896, 1.742557606724184360, -0.879666957860237075
};

float32_t EQ_Band10Coeffs[20] = {  // Band3  //1587 380  4 pole Gaussian 1/3 octave
  -0.074363508404526421, 0.000000000000000000, 0.074363508404526421, 1.717508353369523010, -0.862211252084035151,
  -0.073370934748750075, 0.000000000000000000, 0.073370934748750075, 1.678381089046226960, -0.850702809396297943,
  -0.086324197408935752, 0.000000000000000000, 0.086324197408935752, 1.770356988912942690, -0.890495750927825402,
  -0.0831792956517105050, .000000000000000000, 0.083179295651710505, 1.647225955992196010, -0.858053843143523842
};

float32_t EQ_Band11Coeffs[20] = {  // 2000 480 4 pole 4 pole Gaussian 1/3 octave
  -0.095836703240171059, 0.000000000000000000, 0.095836703240171059, 1.600465210710192880, -0.822735930728153764,
  -0.094139069783896759, 0.000000000000000000, 0.094139069783896759, 1.542179833257436350, -0.808162140160850195,
  -0.111862031820526620, 0.000000000000000000, 0.111862031820526620, 1.675022371378555920, -0.858900156431318784,
  -0.106503914399111971, 0.000000000000000000, 0.106503914399111971, 1.490054957243781340, -0.817759406379379050
};

float32_t EQ_Band12Coeffs[20] = {  // 2500 579  4 pole Gaussian  1/3 octave
  -0.117879553771682077, 0.000000000000000000, 0.117879553771682077, 1.446475829403250920, -0.781724147199137853,
  -0.115383310539578524, 0.000000000000000000, 0.115383310539578524, 1.364990025835680850, -0.765170185554548188,
  -0.138197674814651450, 0.000000000000000000, 0.138197674814651450, 1.546474742602351290, -0.825007082271826175,
  -0.130355600849362346, 0.000000000000000000, 0.130355600849362346, 1.285783233479567580, -0.778191775359172500
};

float32_t EQ_Band13Coeffs[20] = {  //3150 730  4 pole Gaussian  1/3 octave
  -0.150762354328435849, 0.000000000000000000, 0.150762354328435849, 1.219119807012296160, -0.720763563050070721,
  -0.146749880416786549, 0.000000000000000000, 0.146749880416786549, 1.100462092025051410, -0.701580757063202998,
  -0.177820152149393451, 0.000000000000000000, 0.177820152149393451, 1.358721947950491950, -0.774654638713877741,
  -0.165372194155001706, 0.000000000000000000, 0.165372194155001706, 0.976661905865581326, -0.720426429558091441
};

float32_t EQ_Band14Coeffs[20] = {  //4000 919  4 pole Gaussian  1/3 octave
  -0.191002547843707293, 0.000000000000000000, 0.191002547843707293, 0.899547452783356571, -0.644594993669154070,
  -0.185284629488361025, 0.000000000000000000, 0.185284629488361025, 0.731207869008696054, -0.625298174921578354,
  -0.226011710394339427, 0.000000000000000000, 0.226011710394339427, 1.091251019040685220, -0.709544302434661267,
  -0.208696039181478332, 0.000000000000000000, 0.208696039181478332, 0.546857223443984242, -0.655183243751105593
};


//===================End Excite Coefficients ============

float32_t* mag_coeffs[11] = {
  // for Index 0 [1xZoom == no zoom] the mag_coeffs will consist of  a NULL  ptr,
  // since the filter is not going to be used in this  mode!
  (float32_t*)NULL,
  (float32_t*)(const float32_t[]){
    // 2x magnify - index 1
    // 12kHz, sample rate 48k, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH Aug 16th 2016
    0.228454526413293696,
    0.077639329099949764,
    0.228454526413293696,
    0.635534925142242080,
    -0.170083307068779194,
    0.436788292542003964,
    0.232307972937606161,
    0.436788292542003964,
    0.365885230717786780,
    -0.471769788739400842,
    0.535974654742658707,
    0.557035600464780845,
    0.535974654742658707,
    0.125740787233286133,
    -0.754725697183384336,
    0.501116342273565607,
    0.914877831284765408,
    0.501116342273565607,
    0.013862536615004284,
    -0.930973052446900984 },

  (float32_t*)(const float32_t[]){
    // 4x magnify - index 2
    // 6kHz, sample rate 48k, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH Aug 16th 2016
    0.182208761527446556,
    -0.222492493114674145,
    0.182208761527446556,
    1.326111070880959810,
    -0.468036100821178802,

    0.337123762652097259,
    -0.366352718812586853,
    0.337123762652097259,
    1.337053579516321200,
    -0.644948386007929031,

    0.336163175380826074,
    -0.199246162162897811,
    0.336163175380826074,
    1.354952684569386670,
    -0.828032873168141115,

    0.178588201750411041,
    0.207271695028067304,
    0.178588201750411041,
    1.386486967455699220,
    -0.950935065984588657 },

  (float32_t*)(const float32_t[]){
    // 8x magnify - index 3
    // 3kHz, sample rate 48k, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH Aug 16th 2016
    0.185643392652478922,
    -0.332064345389014803,
    0.185643392652478922,
    1.654637402827731090,
    -0.693859842743674182,

    0.327519300813245984,
    -0.571358085216950418,
    0.327519300813245984,
    1.715375037176782860,
    -0.799055553586324407,

    0.283656142708241688,
    -0.441088976843048652,
    0.283656142708241688,
    1.778230635987093860,
    -0.904453944560528522,

    0.079685368654848945,
    -0.011231810140649204,
    0.079685368654848945,
    1.825046003243238070,
    -0.973184930412286708 },

  (float32_t*)(const float32_t[]){
    // 16x magnify - index 4
    // 1k5, sample rate 48k, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH Aug 16th 2016
    0.194769868656866380,
    -0.379098413160710079,
    0.194769868656866380,
    1.824436402073870810,
    -0.834877726226893380,

    0.333973874901496770,
    -0.646106479315673776,
    0.333973874901496770,
    1.871892825636887640,
    -0.893734096124207178,

    0.272903880596429671,
    -0.513507745397738469,
    0.272903880596429671,
    1.918161772571113750,
    -0.950461788366234739,

    0.053535383722369843,
    -0.069683422367188122,
    0.053535383722369843,
    1.948900719896301760,
    -0.986288064973853129 },

  (float32_t*)(const float32_t[]){
    // 32x magnify - index 5
    // 750Hz, sample rate 48k, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH Aug 16th 2016
    0.201507402588557594,
    -0.400273615727755550,
    0.201507402588557594,
    1.910767558906650840,
    -0.913508748356010480,

    0.340295203367131205,
    -0.674930558961690075,
    0.340295203367131205,
    1.939398230905991390,
    -0.945058078678563840,

    0.271859921641011359,
    -0.535453706265515361,
    0.271859921641011359,
    1.966439529620203740,
    -0.974705666636711099,

    0.047026497485465592,
    -0.084562104085501480,
    0.047026497485465592,
    1.983564238653704900,
    -0.993055129539134551 },

  (float32_t*)(const float32_t[]){
    // 64x magnify - index 6
    // 374Hz, sr 48k, 0.02dB ripple, 60dB stopband elliptic
    // DD4WH, 2018_03_24

    0.241056639221550989,
    -0.481274384783607956,
    0.241056639221550989,
    1.949355134029925550,
    -0.950194027689419740,

    0.348059943588306275,
    -0.694622621265274853,
    0.348059943588306275,
    1.966699951543778860,
    -0.968197217455116443,

    0.259592008997311219,
    -0.517100588623714774,
    0.259592008997311219,
    1.983085371558495740,
    -0.985168800929403399,

    0.042223607998797694,
    -0.082088490093798844,
    0.042223607998797694,
    1.993523066505831660,
    -0.995881792409628042 },

  (float32_t*)(const float32_t[]){
    // 128x magnify - index 7
    // 187Hz, sample rate 48k, ripple 0.02dB, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH 2018_03_24
    0.243976032331821663,
    -0.487739726489511083,
    0.243976032331821663,
    1.974570407912224380,
    -0.974782746086356844,

    0.350666090990641666,
    -0.700954871622642472,
    0.350666090990641666,
    1.983591708136026810,
    -0.983969018494667669,

    0.260268176176534360,
    -0.520013508234821287,
    0.260268176176534360,
    1.992032152306574270,
    -0.992554996424821700,

    0.041842895868125313,
    -0.083095418270055094,
    0.041842895868125313,
    1.997347796837673830,
    -0.997938170303869221 },

  // TODO: calculate new coeffs!
  (float32_t*)(const float32_t[]){
    // 256x magnify - index 8
    // 187Hz, sample rate 48k, ripple 0.02dB, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH 2018_03_24
    0.243976032331821663,
    -0.487739726489511083,
    0.243976032331821663,
    1.974570407912224380,
    -0.974782746086356844,

    0.350666090990641666,
    -0.700954871622642472,
    0.350666090990641666,
    1.983591708136026810,
    -0.983969018494667669,

    0.260268176176534360,
    -0.520013508234821287,
    0.260268176176534360,
    1.992032152306574270,
    -0.992554996424821700,

    0.041842895868125313,
    -0.083095418270055094,
    0.041842895868125313,
    1.997347796837673830,
    -0.997938170303869221 },

  // TODO: calculate new coeffs!
  (float32_t*)(const float32_t[]){
    // 512x magnify - index 9
    // 187Hz, sample rate 48k, ripple 0.02dB, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH 2018_03_24
    0.243976032331821663,
    -0.487739726489511083,
    0.243976032331821663,
    1.974570407912224380,
    -0.974782746086356844,

    0.350666090990641666,
    -0.700954871622642472,
    0.350666090990641666,
    1.983591708136026810,
    -0.983969018494667669,

    0.260268176176534360,
    -0.520013508234821287,
    0.260268176176534360,
    1.992032152306574270,
    -0.992554996424821700,

    0.041842895868125313,
    -0.083095418270055094,
    0.041842895868125313,
    1.997347796837673830,
    -0.997938170303869221 },

  (float32_t*)(const float32_t[]){
    // 1024x magnify - index 10
    // 187Hz, sample rate 48k, ripple 0.02dB, 60dB stopband, elliptic
    // a1 and a2 negated! order: b0, b1, b2, a1, a2
    // Iowa Hills IIR Filter Designer, DD4WH 2018_03_24
    0.243976032331821663,
    -0.487739726489511083,
    0.243976032331821663,
    1.974570407912224380,
    -0.974782746086356844,

    0.350666090990641666,
    -0.700954871622642472,
    0.350666090990641666,
    1.983591708136026810,
    -0.983969018494667669,

    0.260268176176534360,
    -0.520013508234821287,
    0.260268176176534360,
    1.992032152306574270,
    -0.992554996424821700,

    0.041842895868125313,
    -0.083095418270055094,
    0.041842895868125313,
    1.997347796837673830,
    -0.997938170303869221 }
};


const float32_t nuttallWindow256[] = {
  0.0000001, 0.0000073, 0.0000292, 0.0000663, 0.0001192, 0.0001891, 0.0002771, 0.0003851,
  0.0005147, 0.0006684, 0.0008485, 0.0010580, 0.0012998, 0.0015775, 0.0018947, 0.0022554,
  0.0026639, 0.0031248, 0.0036429, 0.0042235, 0.0048719, 0.0055940, 0.0063956, 0.0072832,
  0.0082631, 0.0093423, 0.0105278, 0.0118269, 0.0132470, 0.0147960, 0.0164817, 0.0183122,
  0.0202960, 0.0224414, 0.0247569, 0.0272514, 0.0299336, 0.0328123, 0.0358966, 0.0391953,
  0.0427173, 0.0464717, 0.0504671, 0.0547124, 0.0592163, 0.0639871, 0.0690332, 0.0743626,
  0.0799832, 0.0859024, 0.0921274, 0.0986651, 0.1055218, 0.1127036, 0.1202159, 0.1280637,
  0.1362515, 0.1447831, 0.1536618, 0.1628900, 0.1724698, 0.1824023, 0.1926880, 0.2033264,
  0.2143164, 0.2256560, 0.2373424, 0.2493718, 0.2617397, 0.2744405, 0.2874677, 0.3008139,
  0.3144707, 0.3284289, 0.3426782, 0.3572073, 0.3720040, 0.3870552, 0.4023469, 0.4178639,
  0.4335904, 0.4495095, 0.4656036, 0.4818541, 0.4982416, 0.5147460, 0.5313464, 0.5480212,
  0.5647480, 0.5815041, 0.5982659, 0.6150094, 0.6317101, 0.6483431, 0.6648832, 0.6813048,
  0.6975821, 0.7136890, 0.7295995, 0.7452874, 0.7607267, 0.7758911, 0.7907549, 0.8052924,
  0.8194782, 0.8332872, 0.8466949, 0.8596772, 0.8722106, 0.8842721, 0.8958396, 0.9068915,
  0.9174074, 0.9273674, 0.9367527, 0.9455454, 0.9537289, 0.9612875, 0.9682065, 0.9744726,
  0.9800736, 0.9849988, 0.9892383, 0.9927841, 0.9956291, 0.9977678, 0.9991959, 0.9999106,
  0.9999106, 0.9991959, 0.9977678, 0.9956291, 0.9927841, 0.9892383, 0.9849988, 0.9800736,
  0.9744726, 0.9682065, 0.9612875, 0.9537289, 0.9455454, 0.9367527, 0.9273674, 0.9174074,
  0.9068915, 0.8958396, 0.8842721, 0.8722106, 0.8596772, 0.8466949, 0.8332872, 0.8194782,
  0.8052924, 0.7907549, 0.7758911, 0.7607267, 0.7452874, 0.7295995, 0.7136890, 0.6975821,
  0.6813048, 0.6648832, 0.6483431, 0.6317101, 0.6150094, 0.5982659, 0.5815041, 0.5647480,
  0.5480212, 0.5313464, 0.5147460, 0.4982416, 0.4818541, 0.4656036, 0.4495095, 0.4335904,
  0.4178639, 0.4023469, 0.3870552, 0.3720040, 0.3572073, 0.3426782, 0.3284289, 0.3144707,
  0.3008139, 0.2874677, 0.2744405, 0.2617397, 0.2493718, 0.2373424, 0.2256560, 0.2143164,
  0.2033264, 0.1926880, 0.1824023, 0.1724698, 0.1628900, 0.1536618, 0.1447831, 0.1362515,
  0.1280637, 0.1202159, 0.1127036, 0.1055218, 0.0986651, 0.0921274, 0.0859024, 0.0799832,
  0.0743626, 0.0690332, 0.0639871, 0.0592163, 0.0547124, 0.0504671, 0.0464717, 0.0427173,
  0.0391953, 0.0358966, 0.0328123, 0.0299336, 0.0272514, 0.0247569, 0.0224414, 0.0202960,
  0.0183122, 0.0164817, 0.0147960, 0.0132470, 0.0118269, 0.0105278, 0.0093423, 0.0082631,
  0.0072832, 0.0063956, 0.0055940, 0.0048719, 0.0042235, 0.0036429, 0.0031248, 0.0026639,
  0.0022554, 0.0018947, 0.0015775, 0.0012998, 0.0010580, 0.0008485, 0.0006684, 0.0005147,
  0.0003851, 0.0002771, 0.0001891, 0.0001192, 0.0000663, 0.0000292, 0.0000073, 0.0000001
};


/*****
  Purpose: void calc_FIR_coeffs
    // pointer to coefficients variable, no. of coefficients to calculate, frequency where it happens, stopband attenuation in dB,
    // filter type, half-filter bandwidth (only for bandpass and notch)

  Parameter list:
    float * coeffs_I
    int numCoeffs
    float32_t fc
    float32_t Astop
    int type
    float dfc
    float Fsamprate

  Return value;
    void
*****/
void CalcFIRCoeffs(float* coeffs_I, int numCoeffs, float32_t fc, float32_t Astop, int type, float dfc, float Fsamprate)
// pointer to coefficients variable, no. of coefficients to calculate, frequency where it happens, stopband attenuation in dB,
// filter type, half-filter bandwidth (only for bandpass and notch)
{  // modified by WMXZ and DD4WH after
  // Wheatley, M. (2011): CuteSDR Technical Manual. www.metronix.com, pages 118 - 120, FIR with Kaiser-Bessel Window
  // assess required number of coefficients by
  //     numCoeffs = (Astop - 8.0) / (2.285 * TWO_PI * normFtrans);
  // selecting high-pass, numCoeffs is forced to an even number for better frequency response

  float32_t Beta;
  float32_t izb;
  float fcf = fc;
  int nc = numCoeffs;
  fc = fc / Fsamprate;
  dfc = dfc / Fsamprate;
  // calculate Kaiser-Bessel window shape factor beta from stop-band attenuation
  if (Astop < 20.96)
    Beta = 0.0;
  else if (Astop >= 50.0)
    Beta = 0.1102 * (Astop - 8.71);
  else
    Beta = 0.5842 * powf((Astop - 20.96), 0.4) + 0.07886 * (Astop - 20.96);

  for (int i = 0; i < numCoeffs; i++)  //zero pad entire coefficient buffer, important for variables from DMAMEM
  {
    coeffs_I[i] = 0.0;
  }

  izb = Izero(Beta);
  if (type == 0)  // low pass filter
  //     {  fcf = fc;
  {
    fcf = fc * 2.0;
    nc = numCoeffs;
  } else if (type == 1)  // high-pass filter
  {
    fcf = -fc;
    nc = 2 * (numCoeffs / 2);
  } else if ((type == 2) || (type == 3))  // band-pass filter
  {
    fcf = dfc;
    nc = 2 * (numCoeffs / 2);  // maybe not needed
  } else if (type == 4)        // Hilbert transform
  {
    nc = 2 * (numCoeffs / 2);
    // clear coefficients
    for (int ii = 0; ii < 2 * (nc - 1); ii++) coeffs_I[ii] = 0;
    // set real delay
    coeffs_I[nc] = 1;

    // set imaginary Hilbert coefficients
    for (int ii = 1; ii < (nc + 1); ii += 2) {
      if (2 * ii == nc) continue;
      float x = (float)(2 * ii - nc) / (float)nc;
      float w = Izero(Beta * sqrtf(1.0f - x * x)) / izb;  // Kaiser window
      coeffs_I[2 * ii + 1] = 1.0f / (PIH * (float)(ii - nc / 2)) * w;
    }
    return;
  }

  for (int ii = -nc, jj = 0; ii < nc; ii += 2, jj++) {
    float x = (float)ii / (float)nc;
    float w = Izero(Beta * sqrtf(1.0f - x * x)) / izb;  // Kaiser window
    coeffs_I[jj] = fcf * MSinc(ii, fcf) * w;
  }

  if (type == 1) {
    coeffs_I[nc / 2] += 1;
  } else if (type == 2) {
    for (int jj = 0; jj < nc + 1; jj++) coeffs_I[jj] *= 2.0f * cosf(PIH * (2 * jj - nc) * fc);
  } else if (type == 3) {
    for (int jj = 0; jj < nc + 1; jj++) coeffs_I[jj] *= -2.0f * cosf(PIH * (2 * jj - nc) * fc);
    coeffs_I[nc / 2] += 1;
  }

}  // END calc_FIR_coeffs

//////////////////////////////////////////////////////////////////////
//  Call to setup filter parameters
// SampleRate in Hz
// FLowcut is low cutoff frequency of filter in Hz
// FHicut is high cutoff frequency of filter in Hz
// Offset is the CW tone offset frequency
// cutoff frequencies range from -SampleRate/2 to +SampleRate/2
//  HiCut must be greater than LowCut
//    example to make 2700Hz USB filter:
//  SetupParameters( 100, 2800, 0, 48000);
//////////////////////////////////////////////////////////////////////

/*****
  Purpose: void calc_cplx_FIR_coeffs

  Parameter list:
    float *coeffs_I
    float *coeffs_Q
    int numCoeffs
    float32_t FLoCut
    float32_t FHiCut
    float SampleRate

  Return value;
    void
*****/
void CalcCplxFIRCoeffs(float* coeffs_I, float* coeffs_Q, int numCoeffs, float32_t FLoCut, float32_t FHiCut, float SampleRate) {
  //calculate some normalized filter parameters
  float32_t nFL = FLoCut / SampleRate;
  float32_t nFH = FHiCut / SampleRate;
  float32_t nFc = (nFH - nFL) / 2.0;                     //prototype LP filter cutoff
  float32_t nFs = PI * (nFH + nFL);                      //2 PI times required frequency shift (FHiCut+FLoCut)/2
  float32_t fCenter = 0.5 * (float32_t)(numCoeffs - 1);  //floating point center index of FIR filter
  float32_t x;
  float32_t z;

  memset(coeffs_I, 0.0, (size_t)sizeof(n_dec1_taps));  //zero entire buffer, important for variables from DMAMEM
  memset(coeffs_Q, 0.0, (size_t)sizeof(n_dec1_taps));

  //create LP FIR windowed sinc, sin(x)/x complex LP filter coefficients
  for (int i = 0; i < numCoeffs; i++) {
    x = (float32_t)i - fCenter;
    if (abs((float)i - fCenter) < 0.01)  //deal with odd size filter singularity where sin(0)/0==1
      z = 2.0 * nFc;
    else
      switch (FIR_filter_window) {
        case 1:  // 4-term Blackman-Harris --> this is what Power SDR uses
          z = (float32_t)sinf(TWO_PI * x * nFc) / (PI * x) * (0.35875 - 0.48829 * cosf((TWO_PI * i) / (numCoeffs - 1)) + 0.14128 * cosf((FOURPI * i) / (numCoeffs - 1)) - 0.01168 * cosf((SIXPI * i) / (numCoeffs - 1)));
          break;

        case 2:
          z = (float32_t)sinf(TWO_PI * x * nFc) / (PI * x) * (0.355768 - 0.487396 * cosf((TWO_PI * i) / (numCoeffs - 1)) + 0.144232 * cosf((FOURPI * i) / (numCoeffs - 1)) - 0.012604 * cosf((SIXPI * i) / (numCoeffs - 1)));
          break;

        case 3:  // cosine
          z = (float32_t)sinf(TWO_PI * x * nFc) / (PI * x) * cosf((PI * (float32_t)i) / (numCoeffs - 1));
          break;

        case 4:  // Hann
          z = (float32_t)sinf(TWO_PI * x * nFc) / (PI * x) * 0.5 * (float32_t)(1.0 - (cosf(PI * 2 * (float32_t)i / (float32_t)(numCoeffs - 1))));
          break;
        default:  // Blackman-Nuttall window
          z = (float32_t)sinf(TWO_PI * x * nFc) / (PI * x) * (0.3635819 - 0.4891775 * cosf((TWO_PI * i) / (numCoeffs - 1)) + 0.1365995 * cosf((FOURPI * i) / (numCoeffs - 1)) - 0.0106411 * cosf((SIXPI * i) / (numCoeffs - 1)));
          break;
      }
    //shift lowpass filter coefficients in frequency by (hicut+lowcut)/2 to form bandpass filter anywhere in range
    coeffs_I[i] = z * cosf(nFs * x);
    coeffs_Q[i] = z * sinf(nFs * x);
  }
}

/*****
  Purpose: void set_IIR_coeffs

  Parameter list:
    void
  Return value;
    void
*****/
void SetIIRCoeffs(float32_t f0, float32_t Q, float32_t sample_rate, uint8_t filter_type) {

  /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Cascaded biquad (notch, peak, lowShelf, highShelf) [DD4WH, april 2016]
    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
  // DSP Audio-EQ-cookbook for generating the coeffs of the filters on the fly
  // www.musicdsp.org/files/Audio-EQ-Cookbook.txt  [by Robert Bristow-Johnson]
  // https://www.w3.org/2011/audio/audio-eq-cookbook.html
  // the ARM algorithm assumes the biquad form
  // y[n] = b0 * x[n] + b1 * x[n-1] + b2 * x[n-2] + a1 * y[n-1] + a2 * y[n-2]
  //
  // However, the cookbook formulae by Robert Bristow-Johnson AND the Iowa Hills IIR Filter designer
  // use this formula:
  //
  // y[n] = b0 * x[n] + b1 * x[n-1] + b2 * x[n-2] - a1 * y[n-1] - a2 * y[n-2]
  //
  // Therefore, we have to use negated a1 and a2 for use with the ARM function
  if (f0 > sample_rate / 2.0) f0 = sample_rate / 2.0;
  float32_t w0 = f0 * (TWO_PI / sample_rate);
  float32_t sinW0 = sinf(w0);
  float32_t alpha = sinW0 / (Q * 2.0);
  float32_t cosW0 = cosf(w0);
  float32_t scale = 1.0 / (1.0 + alpha);

  if (filter_type == 0) {  // lowpass coeffs

    coefficient_set[0] = ((1.0 - cosW0) / 2.0) * scale; /* b0 */
    coefficient_set[1] = (1.0 - cosW0) * scale;         /* b1 */
    coefficient_set[2] = coefficient_set[0];            /* b2 */
    coefficient_set[3] = (2.0 * cosW0) * scale;         // negated    a1
    coefficient_set[4] = (-1.0 + alpha) * scale;        // negated    a2
  } else if (filter_type == 2) {
    // ??
  } else if (filter_type == 3) {               // notch
    coefficient_set[0] = 1.0;                  /* b0 */
    coefficient_set[1] = -2.0 * cosW0;         /* b1 */
    coefficient_set[2] = 1.0;                  /* b2 */
    coefficient_set[3] = 2.0 * cosW0 * scale;  // negated    a1
    coefficient_set[4] = alpha - 1.0;          // negated    a2
  }
}
