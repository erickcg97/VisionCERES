/*Autores:
    Anniely Soares Lemos 
    Gustavo Henrique do Nascimento
*/

#include "linhas.h"

int main(int argc, char *argv[]){
    string pref = "_metodo3_saida.png";
    string path = "Imagens/";
    string name;
    string name_arq;
    Camera cam(0,4);
    
    cam.img_fn += "Dataset/";
    cam.img_fn += argv[1];
    cam.img_fn += cam.img_ext;
    
    name_arq += argv[1];
    name_arq += "_metodo3";
    name += path;
    name += argv[1];
    name += pref;

    cam.name += argv[1];
    
    cam.dataLog(name_arq, "Metodo3");
    
    cam.frame = imread(cam.img_fn, IMREAD_COLOR);
    cam.gettingSize(cam.frame.cols,cam.frame.rows);
   
    cam.frame.copyTo(cam.frame_final);
    cam.creatingRoi(cam.frame);
    cam.Segmentation(cam.frame_roi);

    //imshow("Seg",cam.segmented);

    cam.erodeConfig(9, 9);
    cam.dilateConfig(3, 3);
    cam.skeletonConfig(3, 3);

    //cam.morphOp(cam.segmented);
    cam.morphologicalOperations(cam.segmented);

    //imshow("E",cam.erosion);
    //imshow("D",cam.dilation);
    //imshow("Morfologica",cam.skeleton);
    //imshow("Bin", cam.binarized);
    
    cam.findingCenters(cam.skeleton);
    cam.ordinating(cam.morph, 30);
    cam.MMQ(2);
    //cam.R2();
    cam.expanding_lines(cam.mmq, 0.3, -0.3);
    cam.drawLines();

    //imshow("Final", cam.frame_final);
    
    cam.writingFile(name_arq);
    imwrite(name,cam.frame_final);
    
    //waitKey(0);

    cam.tempos << ((double)clock()/CLOCKS_PER_SEC)*1000 << endl;
    cam.all << ((double)clock()/CLOCKS_PER_SEC)*1000 << endl;
    
    cam.datalog.close();
    cam.tempos.close();
    cam.all.close();
    
    cam.cap.release();
    destroyAllWindows();
    
	return 0;
}