///*************real-time reconstruction*********************/

#include <cmath>

#include "gen_normal.h"

void SamplePoints(const pcl::PointCloud<pcl::PointXYZ> &vCloud,
				  pcl::PointCloud<pcl::PointXYZ> &vNewCloud,
				  int iSampleNum,
				  bool bIntervalSamp = true)
{

	vNewCloud.clear();

	// sample by interval number
	if (bIntervalSamp)
	{

		for (int i = 0; i < vCloud.points.size(); i = i + iSampleNum)
			vNewCloud.push_back(vCloud.points[i]);

		// over the function and output
		return;

	} // end if

	// Sampling according to the given maximum total number
	// get the interval point number - how muny points should be skipped
	int iInterval = ceil(float(vCloud.points.size()) / float(iSampleNum));
	// sample
	for (int i = 0; i < vCloud.points.size(); i = i + iInterval)
		vNewCloud.push_back(vCloud.points[i]);

	// output
	return;
}

int gen_normal(pcl::PointCloud<pcl::PointXYZ>::Ptr pRawCloud,
			   pcl::PointCloud<pcl::PointNormal>::Ptr pFramePNormal)
{

	pcl::PointCloud<pcl::PointXYZ>::Ptr pSceneCloud(new pcl::PointCloud<pcl::PointXYZ>);
	// pcl::PointCloud<pcl::PointXYZ>::Ptr pRawCloud(new pcl::PointCloud<pcl::PointXYZ>);

	// SamplePoints(*pRawCloud, *pSceneCloud, 3);

	pcl::PointXYZ oViewPoint;
	// x 0.535947 y  0.62239 z 0.535947 bunny
	// x 0.457275 y  0.500000 z 1.814216 Cassette.las
	// x 0.0 -y 0.0 z 0.0 scene1oneframe.las
	oViewPoint.x = 0.0;
	oViewPoint.y = 0.0;
	oViewPoint.z = 0.0;

	// pcl::PointCloud<pcl::PointNormal>::Ptr pFramePNormal(new pcl::PointCloud<pcl::PointNormal>);
	ExplicitRec oExplicitBuilder;
	// oExplicitBuilder.HorizontalSectorSize(12);
	// oExplicitBuilder.SetViewPoint(oViewPoint);
	// oExplicitBuilder.FrameReconstruction(*pSceneCloud, *pFramePNormal);

	return 0;
}