#include "PatchClustering.h" // appease syntax parser

#include "itkImageRegionConstIterator.h"

template <typename TImage>
Eigen::VectorXf PatchClustering::VectorizePatch(const TImage* const image, const itk::ImageRegion<2>& region)
{
  Eigen::VectorXf vectorized = Eigen::VectorXf::Zero(image->GetNumberOfComponentsPerPixel() * region.GetNumberOfPixels());

  itk::ImageRegionConstIterator<TImage> imageIterator(image, region);

  unsigned int numberOfComponentsPerPixel = image->GetNumberOfComponentsPerPixel();
  unsigned int pixelCounter = 0;
  while(!imageIterator.IsAtEnd())
    {
    for(unsigned int component = 0; component < numberOfComponentsPerPixel; ++component)
      {
      vectorized[numberOfComponentsPerPixel * pixelCounter + component] = imageIterator.Get()[component];
      }
    pixelCounter++;
    ++imageIterator;
    }
  return vectorized;
}
