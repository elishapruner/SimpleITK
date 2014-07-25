/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/
#ifndef __sitkSimilarity2DTransform_h
#define __sitkSimilarity2DTransform_h

#include "sitkCommon.h"
#include "sitkTransform.h"

namespace itk
{
namespace simple
{

class SITKCommon_EXPORT Similarity2DTransform
  : public Transform
{
public:
  typedef Similarity2DTransform Self;
  typedef Transform Superclass;

// construct identity
  Similarity2DTransform();

  explicit Similarity2DTransform(const std::vector<double> &fixedCenter,
                            double angle=0.0,
                            const std::vector<double> &translation = std::vector<double>(3,0.0) );

  Similarity2DTransform( const Similarity2DTransform & );

  Similarity2DTransform &operator=( const Similarity2DTransform & );

/** fixed parameter */
  Self &SetCenter(const std::vector<double> &params);
  std::vector<double> GetCenter( ) const;

  double GetAngle () const;

/** parameter */
  Self &SetAngle (double angle);

  std::vector<double> GetTranslation( ) const;
  Self &SetTranslation(const std::vector<double>& translation);

  Self &SetScale(double &scale);
  double GetScale() const;

protected:

  virtual void SetPimpleTransform( PimpleTransformBase *pimpleTransform );

private:

  using Superclass::AddTransform;

  void InternalInitialization(itk::TransformBase *transform);

  template <typename TransformType>
    void InternalInitialization(TransformType *transform);

  nsstd::function<void(const std::vector<double>&)> m_pfSetCenter;
  nsstd::function<std::vector<double>()> m_pfGetCenter;
  nsstd::function<void(double)> m_pfSetAngle;
  nsstd::function<double()> m_pfGetAngle;
  nsstd::function<void(const std::vector<double>&)> m_pfSetTranslation;
  nsstd::function<std::vector<double>()> m_pfGetTranslation;
  nsstd::function<void(double)> m_pfSetScale;
  nsstd::function<double()> m_pfGetScale;

};

}
}

#endif // __sitkSimilarity2DTransform_h
