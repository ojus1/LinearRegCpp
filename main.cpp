#include<fstream>
#include<vector>
#include<iostream>
#include <cstdlib>

int main()
{
	std::vector<double> X,y,theta(2);
	double buffer,dJ0,dJ1,alpha ;
	int m = 0, num_iter = 0,i = 0;
    //X.reserve(201); y.reserve(201);

	alpha = 0.1;
	//theta[0]=28;theta[1]=9;

	std::ifstream fin;
	fin.open("data_X.txt",std::ios::in); if(!fin) std::cout<<"ERROR";
	while(fin >> buffer) X.push_back(buffer);
	fin.close();

	fin.open("data_Y.txt",std::ios::binary);
    while(fin >> buffer) y.push_back(buffer);
	fin.close();

    m = y.size();
	while(num_iter <= 10000)
	{
		for(i=0;i<=m;i++)
		{
				dJ0 = (1.0/m)*(theta[0]+theta[1]*X[i]-y[i]);
				dJ1 = (1.0/m)*(theta[0]+theta[1]*X[i]-y[i])*X[i];
				theta[0] = theta[0]-alpha*dJ0;
				theta[1] = theta[1]-alpha*dJ1;
        }
		num_iter++;
	}
	/*while(num_iter <= m)
	{
        std::cout<<X[num_iter]<<y[num_iter];num_iter++;
    }*/
    std::cout<<"theta0 = "<<theta[0]<<std::endl<<"theta1 = "<<theta[1]<<std::endl;
    std::cout<<"Size of Training Set : " << m << std::endl;

	return 0;
}
